
#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class UBlueprint;
class UAerithOrchestrator;


struct FAirithHistoryEntry
{
	FString Request;
	FString Response;
	FDateTime Timestamp;

	FAirithHistoryEntry(const FString& InRequest, const FString& InResponse)
		: Request(InRequest)
		, Response(InResponse)
		, Timestamp(FDateTime::Now())
	{}
};


class SAerithEditorPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAerithEditorPanel) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	// SWidget overrides
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

private:
	FReply OnSendPrompt();
	FReply OnAnalyzeBlueprint();
	FReply OnCreateBlueprint();
	FReply OnGenerateCpp();
	FReply OnClearOutput();

	void OnPromptTextChanged(const FText& NewText);
	void OnBlueprintSelected(const FAssetData& AssetData);

	void OnOperationComplete(const FString& Result);

	UBlueprint* GetSelectedBlueprint() const;
	void AppendOutput(const FString& Text);
	void ClearOutput();
	void AddToHistory(const FString& Request, const FString& Response);
	void ShowHistoryInOutput();
	FReply OnViewHistory();

	// Timer helper functions
	bool IsSendButtonOnCooldown() const;
	FText GetSendButtonText() const;
	FText GetSendButtonTooltip() const;

	TSharedPtr<class SMultiLineEditableTextBox> PromptTextBox;
	TSharedPtr<class SMultiLineEditableTextBox> OutputTextBox;
	TSharedPtr<class SObjectPropertyEntryBox> BlueprintPicker;

	FText CurrentPromptText;
	FString OutputText;
	FString CurrentRequest;

	UAerithOrchestrator* Orchestrator;

	TWeakObjectPtr<UBlueprint> SelectedBlueprint;

	TArray<FAirithHistoryEntry> History;

	// Cooldown timer tracking
	FDateTime LastBlueprintAnalysisTime;
	bool bHasPerformedAnalysis;
	static constexpr int32 CooldownMinutes = 60;
};
