
#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "AerithEditorStyle.h"

class FAerithEditorCommands : public TCommands<FAerithEditorCommands>
{
public:

	FAerithEditorCommands()
		: TCommands<FAerithEditorCommands>(TEXT("AerithEditor"), NSLOCTEXT("Contexts", "AerithEditor", "Aerith Plugin"), NAME_None, FAerithEditorStyle::GetStyleSetName())
	{
	}

	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> OpenPluginWindow;
};
