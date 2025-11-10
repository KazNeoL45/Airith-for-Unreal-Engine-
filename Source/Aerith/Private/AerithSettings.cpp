
#include "AerithSettings.h"

UAerithSettings::UAerithSettings()
	: ClaudeAPIKey(TEXT(""))
	, APIEndpoint(TEXT("https://api.anthropic.com/v1/messages"))
	, Model(TEXT("claude-3-haiku-20240307"))
	, MaxTokens(4096)
	, Temperature(0.7f)
	, bVerboseLogging(false)
	, MaxContextCharacters(50000) // ~12-15k tokens max, well under the 25k limit
	, bIncludeDetailedNodeAnalysis(false) // Disabled by default to reduce token usage
{
}
