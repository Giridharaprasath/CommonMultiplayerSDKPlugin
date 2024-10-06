// Copyright Melon Studios.

#include "CommonMultiplayerLibrary.h"
#include "CommonMultiplayerSDK.h"
#include "MultiplayerGameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Steam/SteamBlueprintFunctionLibrary.h"

void UCommonMultiplayerLibrary::CreateMultiplayerSession(const UObject* WorldContextObject, ULocalPlayer* LocalPlayer,
                                                         FSessionSettingsInfo SessionSettingsInfo)
{
	GetMultiplayerGameInstanceSubsystem(WorldContextObject)->CreateMultiplayerSession(LocalPlayer, SessionSettingsInfo);
}

void UCommonMultiplayerLibrary::DestroyMultiplayerSession(const UObject* WorldContextObject)
{
	GetMultiplayerGameInstanceSubsystem(WorldContextObject)->DestroyMultiplayerSession();
}

bool UCommonMultiplayerLibrary::UseLanMode(const UObject* WorldContextObject)
{
	bool bUseLanMode = true;
	
	if (USteamBlueprintFunctionLibrary::GetSteamIsOnline(WorldContextObject))
	{
		bUseLanMode = false;
	}
	
	return bUseLanMode;
}

UMultiplayerGameInstanceSubsystem* UCommonMultiplayerLibrary::GetMultiplayerGameInstanceSubsystem(
	const UObject* WorldContextObject)
{
	return UGameplayStatics::GetGameInstance(WorldContextObject)->GetSubsystem<UMultiplayerGameInstanceSubsystem>();
}
