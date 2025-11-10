
#include "AerithEditorPanel.h"
#include "AerithOrchestrator.h"
#include "BlueprintAnalyzer.h"
#include "Engine/Blueprint.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SBox.h"
#include "PropertyCustomizationHelpers.h"
#include "Editor.h"

#define LOCTEXT_NAMESPACE "AerithEditorPanel"

void SAerithEditorPanel::Construct(const FArguments& InArgs)
{
	Orchestrator = NewObject<UAerithOrchestrator>(GetTransientPackage());

	OutputText = TEXT("Airith AI Ready\n\nEnter a prompt and click 'Send' to begin.\n");

	// Initialize cooldown timer
	bHasPerformedAnalysis = false;
	LastBlueprintAnalysisTime = FDateTime::MinValue();

	ChildSlot
	[
		SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10.0f)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("HeaderText", "Airith AI - Blueprint Assistant"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 16))
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10.0f, 5.0f)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0.0f, 0.0f, 10.0f, 0.0f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("BlueprintLabel", "Context Blueprint:"))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SAssignNew(BlueprintPicker, SObjectPropertyEntryBox)
				.AllowedClass(UBlueprint::StaticClass())
				.OnObjectChanged(this, &SAerithEditorPanel::OnBlueprintSelected)
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10.0f, 5.0f)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 5.0f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("PromptLabel", "Your Prompt:"))
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SBox)
				.MinDesiredHeight(100.0f)
				.MaxDesiredHeight(200.0f)
				[
					SAssignNew(PromptTextBox, SMultiLineEditableTextBox)
					.HintText(LOCTEXT("PromptHint", "Enter your instructions here...\nExample: 'Add a health variable and a TakeDamage function'"))
					.OnTextChanged(this, &SAerithEditorPanel::OnPromptTextChanged)
				]
			]
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10.0f, 5.0f)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0.0f, 0.0f, 5.0f, 0.0f)
			[
				SNew(SButton)
				.Text_Lambda([this]() { return GetSendButtonText(); })
				.ToolTipText_Lambda([this]() { return GetSendButtonTooltip(); })
				.OnClicked(this, &SAerithEditorPanel::OnSendPrompt)
				.IsEnabled_Lambda([this]() { return !CurrentPromptText.IsEmpty() && !IsSendButtonOnCooldown(); })
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(5.0f, 0.0f)
			[
				SNew(SButton)
				.Text(LOCTEXT("AnalyzeButton", "Analyze Blueprint"))
				.OnClicked(this, &SAerithEditorPanel::OnAnalyzeBlueprint)
				.IsEnabled_Lambda([this]() { return GetSelectedBlueprint() != nullptr; })
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(5.0f, 0.0f)
			[
				SNew(SButton)
				.Text(LOCTEXT("CreateButton", "Create New Blueprint"))
				.OnClicked(this, &SAerithEditorPanel::OnCreateBlueprint)
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(5.0f, 0.0f)
			[
				SNew(SButton)
				.Text(LOCTEXT("GenerateCppButton", "Generate C++ Code"))
				.OnClicked(this, &SAerithEditorPanel::OnGenerateCpp)
				.IsEnabled_Lambda([this]() { return !CurrentPromptText.IsEmpty(); })
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNullWidget::NullWidget
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(5.0f, 0.0f)
			[
				SNew(SButton)
				.Text(LOCTEXT("ViewHistoryButton", "View History"))
				.OnClicked(this, &SAerithEditorPanel::OnViewHistory)
				.IsEnabled_Lambda([this]() { return History.Num() > 0; })
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				.Text(LOCTEXT("ClearButton", "Clear Output"))
				.OnClicked(this, &SAerithEditorPanel::OnClearOutput)
			]
		]

		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		.Padding(10.0f, 5.0f)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 5.0f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("OutputLabel", "Output:"))
			]

			+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			[
				SNew(SBorder)
				.BorderBackgroundColor(FLinearColor(0.02f, 0.02f, 0.02f))
				[
					SNew(SScrollBox)
					.Orientation(Orient_Vertical)

					+ SScrollBox::Slot()
					[
						SAssignNew(OutputTextBox, SMultiLineEditableTextBox)
						.IsReadOnly(true)
						.Text_Lambda([this]() { return FText::FromString(OutputText); })
						.AutoWrapText(true)
					]
				]
			]
		]
	];
}

void SAerithEditorPanel::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

	// Force UI refresh when cooldown is active to update the timer display
	// No need to do anything special here - the lambda functions will be called automatically
}

FReply SAerithEditorPanel::OnSendPrompt()
{
	if (CurrentPromptText.IsEmpty())
	{
		return FReply::Handled();
	}

	UBlueprint* ContextBlueprint = GetSelectedBlueprint();

	ClearOutput();

	CurrentRequest = CurrentPromptText.ToString();

	AppendOutput(FString::Printf(TEXT("Request:\n%s\n\n=== Processing... ===\n"), *CurrentRequest));

	if (Orchestrator)
	{
		Orchestrator->ProcessPrompt(
			CurrentRequest,
			ContextBlueprint,
			FOnAerithOperationComplete::CreateSP(this, &SAerithEditorPanel::OnOperationComplete)
		);
	}

	return FReply::Handled();
}

FReply SAerithEditorPanel::OnAnalyzeBlueprint()
{
	UBlueprint* Blueprint = GetSelectedBlueprint();
	if (!Blueprint)
	{
		ClearOutput();
		AppendOutput(TEXT("Error: No Blueprint selected\n"));
		return FReply::Handled();
	}

	ClearOutput();

	CurrentRequest = FString::Printf(TEXT("Analyze Blueprint: %s"), *Blueprint->GetName());

	AppendOutput(FString::Printf(TEXT("Request:\n%s\n\n=== Analyzing... ===\n"), *CurrentRequest));

	FString Analysis = UBlueprintAnalyzer::AnalyzeBlueprint(Blueprint);
	AppendOutput(FString::Printf(TEXT("\nResponse:\n%s\n"), *Analysis));

	AddToHistory(CurrentRequest, Analysis);
	CurrentRequest.Empty();

	// Record analysis time for cooldown timer
	LastBlueprintAnalysisTime = FDateTime::Now();
	bHasPerformedAnalysis = true;
	AppendOutput(FString::Printf(TEXT("\n[Note: Send Prompt button will be on cooldown for %d minutes after analysis]\n"), CooldownMinutes));

	return FReply::Handled();
}

FReply SAerithEditorPanel::OnCreateBlueprint()
{
	if (CurrentPromptText.IsEmpty())
	{
		ClearOutput();
		AppendOutput(TEXT("Please enter a description for the Blueprint in the prompt field.\n"));
		return FReply::Handled();
	}

	ClearOutput();

	CurrentRequest = FString::Printf(TEXT("Create Blueprint: %s"), *CurrentPromptText.ToString());

	AppendOutput(FString::Printf(TEXT("Request:\n%s\n\n=== Processing... ===\n"), *CurrentRequest));

	if (Orchestrator)
	{
		Orchestrator->CreateBlueprintFromDescription(
			CurrentPromptText.ToString(),
			AActor::StaticClass(),
			TEXT("/Game/Blueprints"),
			FOnAerithOperationComplete::CreateSP(this, &SAerithEditorPanel::OnOperationComplete)
		);
	}

	return FReply::Handled();
}

FReply SAerithEditorPanel::OnGenerateCpp()
{
	if (CurrentPromptText.IsEmpty())
	{
		return FReply::Handled();
	}

	ClearOutput();

	CurrentRequest = FString::Printf(TEXT("Generate C++ Code: %s"), *CurrentPromptText.ToString());

	AppendOutput(FString::Printf(TEXT("Request:\n%s\n\n=== Processing... ===\n"), *CurrentRequest));

	if (Orchestrator)
	{
		Orchestrator->GenerateCppCode(
			CurrentPromptText.ToString(),
			FOnAerithOperationComplete::CreateSP(this, &SAerithEditorPanel::OnOperationComplete)
		);
	}

	return FReply::Handled();
}

FReply SAerithEditorPanel::OnClearOutput()
{
	OutputText = TEXT("Output cleared.\n");
	return FReply::Handled();
}

void SAerithEditorPanel::OnPromptTextChanged(const FText& NewText)
{
	CurrentPromptText = NewText;
}

void SAerithEditorPanel::OnBlueprintSelected(const FAssetData& AssetData)
{
	UBlueprint* Blueprint = Cast<UBlueprint>(AssetData.GetAsset());
	SelectedBlueprint = Blueprint;
	if (Blueprint)
	{
		AppendOutput(FString::Printf(TEXT("\nSelected Blueprint: %s\n"), *Blueprint->GetName()));
	}
}

void SAerithEditorPanel::OnOperationComplete(const FString& Result)
{
	AppendOutput(FString::Printf(TEXT("\nResponse:\n%s\n"), *Result));

	if (!CurrentRequest.IsEmpty())
	{
		AddToHistory(CurrentRequest, Result);
		CurrentRequest.Empty();
	}
}

UBlueprint* SAerithEditorPanel::GetSelectedBlueprint() const
{
	return SelectedBlueprint.Get();
}

void SAerithEditorPanel::AppendOutput(const FString& Text)
{
	OutputText += Text;

	if (OutputTextBox.IsValid())
	{
		OutputTextBox->ScrollTo(FTextLocation(OutputText.Len()));
	}
}

void SAerithEditorPanel::ClearOutput()
{
	OutputText.Empty();
}

void SAerithEditorPanel::AddToHistory(const FString& Request, const FString& Response)
{
	History.Add(FAirithHistoryEntry(Request, Response));

	if (History.Num() > 50)
	{
		History.RemoveAt(0);
	}
}

void SAerithEditorPanel::ShowHistoryInOutput()
{
	ClearOutput();

	if (History.Num() == 0)
	{
		OutputText = TEXT("No history available.\n");
		return;
	}

	OutputText = FString::Printf(TEXT("=== History (%d entries) ===\n\n"), History.Num());

	for (int32 i = History.Num() - 1; i >= 0; --i)
	{
		const FAirithHistoryEntry& Entry = History[i];
		FString TimeStr = Entry.Timestamp.ToString(TEXT("%Y-%m-%d %H:%M:%S"));

		OutputText += FString::Printf(
			TEXT("--- Entry #%d (%s) ---\n\nRequest:\n%s\n\nResponse:\n%s\n\n========================================\n\n"),
			History.Num() - i,
			*TimeStr,
			*Entry.Request,
			*Entry.Response
		);
	}
}

FReply SAerithEditorPanel::OnViewHistory()
{
	ShowHistoryInOutput();
	return FReply::Handled();
}

bool SAerithEditorPanel::IsSendButtonOnCooldown() const
{
	if (!bHasPerformedAnalysis)
	{
		return false;
	}

	FTimespan TimeSinceAnalysis = FDateTime::Now() - LastBlueprintAnalysisTime;
	return TimeSinceAnalysis.GetTotalMinutes() < CooldownMinutes;
}

FText SAerithEditorPanel::GetSendButtonText() const
{
	if (IsSendButtonOnCooldown())
	{
		FTimespan TimeSinceAnalysis = FDateTime::Now() - LastBlueprintAnalysisTime;
		int32 MinutesRemaining = CooldownMinutes - static_cast<int32>(TimeSinceAnalysis.GetTotalMinutes());
		int32 SecondsRemaining = static_cast<int32>((CooldownMinutes * 60) - TimeSinceAnalysis.GetTotalSeconds()) % 60;

		return FText::FromString(FString::Printf(TEXT("Send Prompt (%d:%02d)"), MinutesRemaining, SecondsRemaining));
	}

	return LOCTEXT("SendButton", "Send Prompt");
}

FText SAerithEditorPanel::GetSendButtonTooltip() const
{
	if (IsSendButtonOnCooldown())
	{
		FTimespan TimeSinceAnalysis = FDateTime::Now() - LastBlueprintAnalysisTime;
		int32 MinutesRemaining = CooldownMinutes - static_cast<int32>(TimeSinceAnalysis.GetTotalMinutes());
		int32 SecondsRemaining = static_cast<int32>((CooldownMinutes * 60) - TimeSinceAnalysis.GetTotalSeconds()) % 60;

		return FText::FromString(FString::Printf(
			TEXT("This button is on cooldown after blueprint analysis to prevent rate limit errors.\nTime remaining: %d minutes %d seconds"),
			MinutesRemaining,
			SecondsRemaining
		));
	}

	return LOCTEXT("SendButtonTooltip", "Send your prompt to the AI");
}

#undef LOCTEXT_NAMESPACE
