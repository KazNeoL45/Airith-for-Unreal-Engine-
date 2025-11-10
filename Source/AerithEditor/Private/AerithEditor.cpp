
#include "AerithEditor.h"
#include "AerithEditorStyle.h"
#include "AerithEditorCommands.h"
#include "AerithSettings.h"
#include "AerithEditorPanel.h"
#include "AerithContentBrowserExtensions.h"
#include "ToolMenus.h"
#include "WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructureModule.h"
#include "Widgets/Docking/SDockTab.h"
#include "ISettingsModule.h"

static const FName AerithEditorTabName("AerithEditor");

#define LOCTEXT_NAMESPACE "FAerithEditorModule"

void FAerithEditorModule::StartupModule()
{
	FAerithEditorStyle::Initialize();
	FAerithEditorStyle::ReloadTextures();
	FAerithEditorCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FAerithEditorCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateLambda([]()
		{
			FGlobalTabmanager::Get()->TryInvokeTab(AerithEditorTabName);
		}),
		FCanExecuteAction());

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(AerithEditorTabName,
		FOnSpawnTab::CreateLambda([](const FSpawnTabArgs& Args) -> TSharedRef<SDockTab>
		{
			return SNew(SDockTab)
				.TabRole(ETabRole::NomadTab)
				[
					SNew(SAerithEditorPanel)
				];
		}))
		.SetDisplayName(LOCTEXT("FAerithEditorTabTitle", "Airith AI"))
		.SetMenuType(ETabSpawnerMenuType::Hidden)
		.SetGroup(WorkspaceMenu::GetMenuStructure().GetToolsCategory());

	RegisterMenus();
	RegisterSettings();

	FAerithContentBrowserExtensions::InstallHooks();
}

void FAerithEditorModule::ShutdownModule()
{
	FAerithContentBrowserExtensions::RemoveHooks();

	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);

	FAerithEditorStyle::Shutdown();
	FAerithEditorCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(AerithEditorTabName);

	UnregisterSettings();
}

void FAerithEditorModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FAerithEditorCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FAerithEditorCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

void FAerithEditorModule::RegisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Aerith",
			LOCTEXT("RuntimeSettingsName", "Airith AI"),
			LOCTEXT("RuntimeSettingsDescription", "Configure Airith AI settings"),
			GetMutableDefault<UAerithSettings>()
		);
	}
}

void FAerithEditorModule::UnregisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "Aerith");
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAerithEditorModule, AerithEditor)
