
#include "AerithEditorCommands.h"

#define LOCTEXT_NAMESPACE "FAerithEditorModule"

void FAerithEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "Airith AI", "Open Airith AI window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
