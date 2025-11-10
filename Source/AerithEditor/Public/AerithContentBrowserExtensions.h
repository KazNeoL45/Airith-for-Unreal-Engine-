
#pragma once

#include "CoreMinimal.h"


class FAerithContentBrowserExtensions
{
public:
	static void InstallHooks();
	static void RemoveHooks();

private:
	static void OnExtendContentBrowserAssetSelectionMenu(class FMenuBuilder& MenuBuilder, TArray<struct FAssetData> SelectedAssets);

	static void ExecuteAnalyzeBlueprint(TArray<FAssetData> SelectedAssets);
	static void ExecuteModifyWithAI(TArray<FAssetData> SelectedAssets);

	static TSharedRef<class FExtender> OnExtendContentBrowserAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets);

	static FDelegateHandle ContentBrowserExtenderDelegateHandle;
};
