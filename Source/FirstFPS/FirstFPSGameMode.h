// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "GameSparks/Private/GameSparksComponent.h"
#include "GameSparksModule.h"
#include <GameSparks/GS.h>
#include <GameSparks/generated/GSResponses.h>
#include <GameSparks/generated/GSRequests.h>
#include <GameSparks/generated/GSMessages.h>
#include <GameSparks/Private/RT/UGSRTSession.h>
#include "FirstFPSGameMode.generated.h"

UCLASS(minimalapi)
class AFirstFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFirstFPSGameMode();

	//USceneComponent Root;

	UGameSparksComponent* GameSparksComp;
	static UGSRTSession GameSession;

	//BeginPlay
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type) override;

	//Function used to determine what happens if GameSparks connects or fails to (Needs to be UFUNCTION)
	UFUNCTION()
	void OnGameSparksAvailable(bool available);

	static void DeviceAuthenticationRequest_Response(GameSparks::Core::GS&, const GameSparks::Api::Responses::AuthenticationResponse&);

	static void Matchmaking_Response(GameSparks::Core::GS&, const GameSparks::Api::Responses::MatchmakingResponse&);
	

	static void OnMatchFoundMessage(GameSparks::Core::GS& gs, const GameSparks::Api::Messages::MatchFoundMessage& message);
	static void OnMatchNotFoundMessage(GameSparks::Core::GS& gs, const GameSparks::Api::Messages::MatchNotFoundMessage& message);
};



