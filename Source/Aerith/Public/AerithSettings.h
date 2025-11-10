
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AerithSettings.generated.h"


UCLASS(config = Editor, defaultconfig)
class AERITH_API UAerithSettings : public UObject
{
	GENERATED_BODY()

public:
	UAerithSettings();

	UPROPERTY(Config, EditAnywhere, Category = "AI API", meta = (DisplayName = "Claude API Key"))
	FString ClaudeAPIKey;

	UPROPERTY(Config, EditAnywhere, Category = "AI API", meta = (DisplayName = "API Endpoint"))
	FString APIEndpoint;

	UPROPERTY(Config, EditAnywhere, Category = "AI API", meta = (DisplayName = "Model"))
	FString Model;

	UPROPERTY(Config, EditAnywhere, Category = "AI API", meta = (DisplayName = "Max Tokens", ClampMin = "1024", ClampMax = "200000"))
	int32 MaxTokens;

	UPROPERTY(Config, EditAnywhere, Category = "AI API", meta = (DisplayName = "Temperature", ClampMin = "0.0", ClampMax = "1.0"))
	float Temperature;

	UPROPERTY(Config, EditAnywhere, Category = "Debug", meta = (DisplayName = "Verbose Logging"))
	bool bVerboseLogging;

	UPROPERTY(Config, EditAnywhere, Category = "Advanced", meta = (DisplayName = "Max Context Characters", ClampMin = "1000", ClampMax = "100000"))
	int32 MaxContextCharacters;

	UPROPERTY(Config, EditAnywhere, Category = "Advanced", meta = (DisplayName = "Include Detailed Node Analysis"))
	bool bIncludeDetailedNodeAnalysis;
};
