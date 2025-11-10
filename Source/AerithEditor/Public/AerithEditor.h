
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FAerithEditorModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void RegisterMenus();
	void RegisterSettings();
	void UnregisterSettings();

	TSharedPtr<class FUICommandList> PluginCommands;
};
