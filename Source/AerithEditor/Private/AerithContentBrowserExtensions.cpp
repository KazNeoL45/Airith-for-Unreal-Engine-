
#include "AerithContentBrowserExtensions.h"
#include "BlueprintAnalyzer.h"
#include "AerithOrchestrator.h"
#include "Engine/Blueprint.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "ToolMenus.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Misc/MessageDialog.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Layout/SBox.h"
#include "Framework/Application/SlateApplication.h"

#define LOCTEXT_NAMESPACE "AerithContentBrowser"

FDelegateHandle FAerithContentBrowserExtensions::ContentBrowserExtenderDelegateHandle;

void FAerithContentBrowserExtensions::InstallHooks()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));
	TArray<FContentBrowserMenuExtender_SelectedAssets>& CBMenuExtenderDelegates = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();

	CBMenuExtenderDelegates.Add(FContentBrowserMenuExtender_SelectedAssets::CreateStatic(&FAerithContentBrowserExtensions::OnExtendContentBrowserAssetSelectionMenu));
	ContentBrowserExtenderDelegateHandle = CBMenuExtenderDelegates.Last().GetHandle();
}

void FAerithContentBrowserExtensions::RemoveHooks()
{
	if (ContentBrowserExtenderDelegateHandle.IsValid())
	{
		FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));
		TArray<FContentBrowserMenuExtender_SelectedAssets>& CBMenuExtenderDelegates = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();
		CBMenuExtenderDelegates.RemoveAll([](const FContentBrowserMenuExtender_SelectedAssets& Delegate)
		{
			return Delegate.GetHandle() == ContentBrowserExtenderDelegateHandle;
		});
	}
}

TSharedRef<FExtender> FAerithContentBrowserExtensions::OnExtendContentBrowserAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	bool bHasBlueprint = false;
	for (const FAssetData& Asset : SelectedAssets)
	{
		if (Asset.AssetClassPath.GetAssetName() == UBlueprint::StaticClass()->GetFName())
		{
			bHasBlueprint = true;
			break;
		}
	}

	if (bHasBlueprint)
	{
		Extender->AddMenuExtension(
			"CommonAssetActions",
			EExtensionHook::After,
			nullptr,
			FMenuExtensionDelegate::CreateLambda([SelectedAssets](FMenuBuilder& MenuBuilder)
			{
				MenuBuilder.BeginSection("Aerith", LOCTEXT("AerithSection", "Aerith AI"));
				{
					MenuBuilder.AddMenuEntry(
						LOCTEXT("AnalyzeBlueprint", "Analyze with Aerith"),
						LOCTEXT("AnalyzeBlueprintTooltip", "Analyze this Blueprint with Aerith AI"),
						FSlateIcon(),
						FUIAction(FExecuteAction::CreateStatic(&FAerithContentBrowserExtensions::ExecuteAnalyzeBlueprint, SelectedAssets))
					);

					MenuBuilder.AddMenuEntry(
						LOCTEXT("ModifyBlueprint", "Modify with Aerith"),
						LOCTEXT("ModifyBlueprintTooltip", "Use Aerith AI to modify this Blueprint"),
						FSlateIcon(),
						FUIAction(FExecuteAction::CreateStatic(&FAerithContentBrowserExtensions::ExecuteModifyWithAI, SelectedAssets))
					);
				}
				MenuBuilder.EndSection();
			})
		);
	}

	return Extender;
}

void FAerithContentBrowserExtensions::ExecuteAnalyzeBlueprint(TArray<FAssetData> SelectedAssets)
{
	for (const FAssetData& Asset : SelectedAssets)
	{
		if (UBlueprint* Blueprint = Cast<UBlueprint>(Asset.GetAsset()))
		{
			FString Analysis = UBlueprintAnalyzer::AnalyzeBlueprint(Blueprint);

			FText Title = FText::Format(LOCTEXT("AnalysisTitle", "Blueprint Analysis: {0}"), FText::FromString(Blueprint->GetName()));
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(Analysis), Title);

			UE_LOG(LogTemp, Log, TEXT("Aerith: Analyzed Blueprint %s"), *Blueprint->GetName());
		}
	}
}

void FAerithContentBrowserExtensions::ExecuteModifyWithAI(TArray<FAssetData> SelectedAssets)
{
	if (SelectedAssets.Num() == 0)
	{
		return;
	}

	UBlueprint* Blueprint = Cast<UBlueprint>(SelectedAssets[0].GetAsset());
	if (!Blueprint)
	{
		return;
	}

	TSharedPtr<SWindow> Window = SNew(SWindow)
		.Title(LOCTEXT("ModifyDialogTitle", "Modify Blueprint with Aerith"))
		.ClientSize(FVector2D(600, 300))
		.SupportsMaximize(false)
		.SupportsMinimize(false);

	TSharedPtr<SMultiLineEditableTextBox> InputTextBox;
	FText UserInput;

	Window->SetContent(
		SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		.Padding(10.0f)
		[
			SNew(SBox)
			[
				SAssignNew(InputTextBox, SMultiLineEditableTextBox)
				.HintText(LOCTEXT("ModifyHint", "Enter your instructions for modifying this Blueprint..."))
				.OnTextChanged_Lambda([&UserInput](const FText& NewText) { UserInput = NewText; })
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10.0f)
		.HAlign(HAlign_Right)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(5.0f, 0.0f)
			[
				SNew(SButton)
				.Text(LOCTEXT("OKButton", "OK"))
				.OnClicked_Lambda([Window, &UserInput, Blueprint]()
				{
					if (!UserInput.IsEmpty())
					{
						UAerithOrchestrator* Orchestrator = NewObject<UAerithOrchestrator>(GetTransientPackage());
						Orchestrator->ModifyBlueprint(
							Blueprint,
							UserInput.ToString(),
							FOnAerithOperationComplete::CreateLambda([](const FString& Result)
							{
								FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(Result), LOCTEXT("ResultTitle", "Aerith Result"));
							})
						);
					}

					Window->RequestDestroyWindow();
					return FReply::Handled();
				})
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				.Text(LOCTEXT("CancelButton", "Cancel"))
				.OnClicked_Lambda([Window]()
				{
					Window->RequestDestroyWindow();
					return FReply::Handled();
				})
			]
		]
	);

	FSlateApplication::Get().AddWindow(Window.ToSharedRef());
}

#undef LOCTEXT_NAMESPACE
