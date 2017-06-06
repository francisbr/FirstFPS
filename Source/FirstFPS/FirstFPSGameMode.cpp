// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FirstFPS.h"
#include "FirstFPSGameMode.h"
#include "FirstFPSHUD.h"
#include "FirstFPSCharacter.h"
#include "GameSparks/Private/GameSparksComponent.h"
#include "GameSparksModule.h"
#include <GameSparks/GS.h>
#include <GameSparks/generated/GSResponses.h>
#include <GameSparks/generated/GSRequests.h>
#include <GameSparks/generated/GSMessages.h>




AFirstFPSGameMode::AFirstFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFirstFPSHUD::StaticClass();

	GameSparksComp = CreateDefaultSubobject<UGameSparksComponent>(TEXT("GSparkComp"));
}

void AFirstFPSGameMode::BeginPlay() {

	Super::BeginPlay();
	//Add a function to the OnGameSparksAvailableDelegate invocation list
	GameSparksComp->OnGameSparksAvailableDelegate.AddDynamic(this, &AFirstFPSGameMode::OnGameSparksAvailable);
	//Connect to GameSparks using Key and Secret
	GameSparksComp->Connect("U311208z2daL", "X8iJtbJznd2LgFYijUPv1Ldef53e18rT");

}

void AFirstFPSGameMode::EndPlay(const EEndPlayReason::Type) {
	GameSparksComp->Disconnect();
}

void AFirstFPSGameMode::OnGameSparksAvailable(bool available) {
	if (available) {
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, TEXT("Connected"));
		//Get a pointer to the module's GSInstance
		GameSparks::Core::GS& gs = UGameSparksModule::GetModulePtr()->GetGSInstance();
		int ran = rand() % 2147483647 + 1;

		std::string nom = "player" + ran;
		//Construct an Authentication request
		GameSparks::Api::Requests::DeviceAuthenticationRequest authRequest(gs);
		authRequest.SetDeviceId(nom);
		authRequest.SetDeviceOS(nom);

		//Send it with a pointer to the function that will handle the response
		authRequest.Send(DeviceAuthenticationRequest_Response);
	} else {
	}

}

//Example response function
void AFirstFPSGameMode::DeviceAuthenticationRequest_Response(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response) {

	//Check is response has no errors
	if (!response.GetHasErrors()) {

		//GameSparks::Core::GS& gs = UGameSparksModule::GetModulePtr()->GetGSInstance();
		GameSparks::Api::Requests::MatchmakingRequest Request(gsInstance);

		Request.SetMatchShortCode("MUTLI_MATCH");
		Request.SetSkill(1.f);

		//If no errors then send an accounts details request
		Request.Send(Matchmaking_Response);

	}
	

}

void AFirstFPSGameMode::Matchmaking_Response(GameSparks::Core::GS& gs, const GameSparks::Api::Responses::MatchmakingResponse& response) {

	if (!response.GetHasErrors()) {
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Green, TEXT("Matchmaking.."));

		gs.SetMessageListener<GameSparks::Api::Messages::MatchFoundMessage>(OnMatchFoundMessage);
		gs.SetMessageListener<GameSparks::Api::Messages::MatchNotFoundMessage>(OnMatchNotFoundMessage);
	}
}

void AFirstFPSGameMode::OnMatchFoundMessage(GameSparks::Core::GS& gs, const GameSparks::Api::Messages::MatchFoundMessage& message) {
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Green, TEXT("Match Found"));
	UE_LOG(LogTemp, Warning, TEXT("MATCH FOUND"));

	//GameSession.CreateRTSession(GetWorld(), message.GetHost().GetValue().c_str(), message.GetPort().GetValue().c_str(), message.GetAccessToken().GetValue().c_str());
	//GameSession.FOnData(OnMatchFoundMessage);

	//UGSRTSession GameSession = UGSRTSession::CreateRTSession(GetWorld(), message.GetHost().GetValue().c_str(), message.GetPort().GetValue().c_str(), message.GetAccessToken().GetValue().c_str());


}

void AFirstFPSGameMode::OnMatchNotFoundMessage(GameSparks::Core::GS& gs, const GameSparks::Api::Messages::MatchNotFoundMessage& message) {
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("Match Not Found"));
	UE_LOG(LogTemp, Warning, TEXT("MATCH NOT FOUND"));
}