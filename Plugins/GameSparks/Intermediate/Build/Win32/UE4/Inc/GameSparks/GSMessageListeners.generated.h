// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGSUploadCompleteMessage;
struct FGSTeamRankChangedMessage;
struct FGSTeamChatMessage;
struct FGSSocialRankChangedMessage;
struct FGSSessionTerminatedMessage;
struct FGSScriptMessage;
struct FGSNewTeamScoreMessage;
struct FGSNewHighScoreMessage;
struct FGSMatchUpdatedMessage;
struct FGSMatchNotFoundMessage;
struct FGSMatchFoundMessage;
struct FGSGlobalRankChangedMessage;
struct FGSFriendMessage;
struct FGSChallengeWonMessage;
struct FGSChallengeWithdrawnMessage;
struct FGSChallengeWaitingMessage;
struct FGSChallengeTurnTakenMessage;
struct FGSChallengeStartedMessage;
struct FGSChallengeLostMessage;
struct FGSChallengeLapsedMessage;
struct FGSChallengeJoinedMessage;
struct FGSChallengeIssuedMessage;
struct FGSChallengeExpiredMessage;
struct FGSChallengeDrawnMessage;
struct FGSChallengeDeclinedMessage;
struct FGSChallengeChatMessage;
struct FGSChallengeChangedMessage;
struct FGSChallengeAcceptedMessage;
struct FGSAchievementEarnedMessage;
#ifdef GAMESPARKS_GSMessageListeners_generated_h
#error "GSMessageListeners.generated.h already included, missing '#pragma once' in GSMessageListeners.h"
#endif
#define GAMESPARKS_GSMessageListeners_generated_h

#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_160_DELEGATE \
struct GSMessageListeners_eventOnUploadCompleteMessage_Parms \
{ \
	FGSUploadCompleteMessage UploadCompleteMessage; \
}; \
static inline void FOnUploadCompleteMessage_DelegateWrapper(const FMulticastScriptDelegate& OnUploadCompleteMessage, FGSUploadCompleteMessage UploadCompleteMessage) \
{ \
	GSMessageListeners_eventOnUploadCompleteMessage_Parms Parms; \
	Parms.UploadCompleteMessage=UploadCompleteMessage; \
	OnUploadCompleteMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_155_DELEGATE \
struct GSMessageListeners_eventOnTeamRankChangedMessage_Parms \
{ \
	FGSTeamRankChangedMessage TeamRankChangedMessage; \
}; \
static inline void FOnTeamRankChangedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnTeamRankChangedMessage, FGSTeamRankChangedMessage TeamRankChangedMessage) \
{ \
	GSMessageListeners_eventOnTeamRankChangedMessage_Parms Parms; \
	Parms.TeamRankChangedMessage=TeamRankChangedMessage; \
	OnTeamRankChangedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_150_DELEGATE \
struct GSMessageListeners_eventOnTeamChatMessage_Parms \
{ \
	FGSTeamChatMessage TeamChatMessage; \
}; \
static inline void FOnTeamChatMessage_DelegateWrapper(const FMulticastScriptDelegate& OnTeamChatMessage, FGSTeamChatMessage TeamChatMessage) \
{ \
	GSMessageListeners_eventOnTeamChatMessage_Parms Parms; \
	Parms.TeamChatMessage=TeamChatMessage; \
	OnTeamChatMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_145_DELEGATE \
struct GSMessageListeners_eventOnSocialRankChangedMessage_Parms \
{ \
	FGSSocialRankChangedMessage SocialRankChangedMessage; \
}; \
static inline void FOnSocialRankChangedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnSocialRankChangedMessage, FGSSocialRankChangedMessage SocialRankChangedMessage) \
{ \
	GSMessageListeners_eventOnSocialRankChangedMessage_Parms Parms; \
	Parms.SocialRankChangedMessage=SocialRankChangedMessage; \
	OnSocialRankChangedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_140_DELEGATE \
struct GSMessageListeners_eventOnSessionTerminatedMessage_Parms \
{ \
	FGSSessionTerminatedMessage SessionTerminatedMessage; \
}; \
static inline void FOnSessionTerminatedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnSessionTerminatedMessage, FGSSessionTerminatedMessage SessionTerminatedMessage) \
{ \
	GSMessageListeners_eventOnSessionTerminatedMessage_Parms Parms; \
	Parms.SessionTerminatedMessage=SessionTerminatedMessage; \
	OnSessionTerminatedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_135_DELEGATE \
struct GSMessageListeners_eventOnScriptMessage_Parms \
{ \
	FGSScriptMessage ScriptMessage; \
}; \
static inline void FOnScriptMessage_DelegateWrapper(const FMulticastScriptDelegate& OnScriptMessage, FGSScriptMessage ScriptMessage) \
{ \
	GSMessageListeners_eventOnScriptMessage_Parms Parms; \
	Parms.ScriptMessage=ScriptMessage; \
	OnScriptMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_130_DELEGATE \
struct GSMessageListeners_eventOnNewTeamScoreMessage_Parms \
{ \
	FGSNewTeamScoreMessage NewTeamScoreMessage; \
}; \
static inline void FOnNewTeamScoreMessage_DelegateWrapper(const FMulticastScriptDelegate& OnNewTeamScoreMessage, FGSNewTeamScoreMessage NewTeamScoreMessage) \
{ \
	GSMessageListeners_eventOnNewTeamScoreMessage_Parms Parms; \
	Parms.NewTeamScoreMessage=NewTeamScoreMessage; \
	OnNewTeamScoreMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_125_DELEGATE \
struct GSMessageListeners_eventOnNewHighScoreMessage_Parms \
{ \
	FGSNewHighScoreMessage NewHighScoreMessage; \
}; \
static inline void FOnNewHighScoreMessage_DelegateWrapper(const FMulticastScriptDelegate& OnNewHighScoreMessage, FGSNewHighScoreMessage NewHighScoreMessage) \
{ \
	GSMessageListeners_eventOnNewHighScoreMessage_Parms Parms; \
	Parms.NewHighScoreMessage=NewHighScoreMessage; \
	OnNewHighScoreMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_120_DELEGATE \
struct GSMessageListeners_eventOnMatchUpdatedMessage_Parms \
{ \
	FGSMatchUpdatedMessage MatchUpdatedMessage; \
}; \
static inline void FOnMatchUpdatedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnMatchUpdatedMessage, FGSMatchUpdatedMessage MatchUpdatedMessage) \
{ \
	GSMessageListeners_eventOnMatchUpdatedMessage_Parms Parms; \
	Parms.MatchUpdatedMessage=MatchUpdatedMessage; \
	OnMatchUpdatedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_115_DELEGATE \
struct GSMessageListeners_eventOnMatchNotFoundMessage_Parms \
{ \
	FGSMatchNotFoundMessage MatchNotFoundMessage; \
}; \
static inline void FOnMatchNotFoundMessage_DelegateWrapper(const FMulticastScriptDelegate& OnMatchNotFoundMessage, FGSMatchNotFoundMessage MatchNotFoundMessage) \
{ \
	GSMessageListeners_eventOnMatchNotFoundMessage_Parms Parms; \
	Parms.MatchNotFoundMessage=MatchNotFoundMessage; \
	OnMatchNotFoundMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_110_DELEGATE \
struct GSMessageListeners_eventOnMatchFoundMessage_Parms \
{ \
	FGSMatchFoundMessage MatchFoundMessage; \
}; \
static inline void FOnMatchFoundMessage_DelegateWrapper(const FMulticastScriptDelegate& OnMatchFoundMessage, FGSMatchFoundMessage MatchFoundMessage) \
{ \
	GSMessageListeners_eventOnMatchFoundMessage_Parms Parms; \
	Parms.MatchFoundMessage=MatchFoundMessage; \
	OnMatchFoundMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_105_DELEGATE \
struct GSMessageListeners_eventOnGlobalRankChangedMessage_Parms \
{ \
	FGSGlobalRankChangedMessage GlobalRankChangedMessage; \
}; \
static inline void FOnGlobalRankChangedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnGlobalRankChangedMessage, FGSGlobalRankChangedMessage GlobalRankChangedMessage) \
{ \
	GSMessageListeners_eventOnGlobalRankChangedMessage_Parms Parms; \
	Parms.GlobalRankChangedMessage=GlobalRankChangedMessage; \
	OnGlobalRankChangedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_100_DELEGATE \
struct GSMessageListeners_eventOnFriendMessage_Parms \
{ \
	FGSFriendMessage FriendMessage; \
}; \
static inline void FOnFriendMessage_DelegateWrapper(const FMulticastScriptDelegate& OnFriendMessage, FGSFriendMessage FriendMessage) \
{ \
	GSMessageListeners_eventOnFriendMessage_Parms Parms; \
	Parms.FriendMessage=FriendMessage; \
	OnFriendMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_95_DELEGATE \
struct GSMessageListeners_eventOnChallengeWonMessage_Parms \
{ \
	FGSChallengeWonMessage ChallengeWonMessage; \
}; \
static inline void FOnChallengeWonMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeWonMessage, FGSChallengeWonMessage ChallengeWonMessage) \
{ \
	GSMessageListeners_eventOnChallengeWonMessage_Parms Parms; \
	Parms.ChallengeWonMessage=ChallengeWonMessage; \
	OnChallengeWonMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_90_DELEGATE \
struct GSMessageListeners_eventOnChallengeWithdrawnMessage_Parms \
{ \
	FGSChallengeWithdrawnMessage ChallengeWithdrawnMessage; \
}; \
static inline void FOnChallengeWithdrawnMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeWithdrawnMessage, FGSChallengeWithdrawnMessage ChallengeWithdrawnMessage) \
{ \
	GSMessageListeners_eventOnChallengeWithdrawnMessage_Parms Parms; \
	Parms.ChallengeWithdrawnMessage=ChallengeWithdrawnMessage; \
	OnChallengeWithdrawnMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_85_DELEGATE \
struct GSMessageListeners_eventOnChallengeWaitingMessage_Parms \
{ \
	FGSChallengeWaitingMessage ChallengeWaitingMessage; \
}; \
static inline void FOnChallengeWaitingMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeWaitingMessage, FGSChallengeWaitingMessage ChallengeWaitingMessage) \
{ \
	GSMessageListeners_eventOnChallengeWaitingMessage_Parms Parms; \
	Parms.ChallengeWaitingMessage=ChallengeWaitingMessage; \
	OnChallengeWaitingMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_80_DELEGATE \
struct GSMessageListeners_eventOnChallengeTurnTakenMessage_Parms \
{ \
	FGSChallengeTurnTakenMessage ChallengeTurnTakenMessage; \
}; \
static inline void FOnChallengeTurnTakenMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeTurnTakenMessage, FGSChallengeTurnTakenMessage ChallengeTurnTakenMessage) \
{ \
	GSMessageListeners_eventOnChallengeTurnTakenMessage_Parms Parms; \
	Parms.ChallengeTurnTakenMessage=ChallengeTurnTakenMessage; \
	OnChallengeTurnTakenMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_75_DELEGATE \
struct GSMessageListeners_eventOnChallengeStartedMessage_Parms \
{ \
	FGSChallengeStartedMessage ChallengeStartedMessage; \
}; \
static inline void FOnChallengeStartedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeStartedMessage, FGSChallengeStartedMessage ChallengeStartedMessage) \
{ \
	GSMessageListeners_eventOnChallengeStartedMessage_Parms Parms; \
	Parms.ChallengeStartedMessage=ChallengeStartedMessage; \
	OnChallengeStartedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_70_DELEGATE \
struct GSMessageListeners_eventOnChallengeLostMessage_Parms \
{ \
	FGSChallengeLostMessage ChallengeLostMessage; \
}; \
static inline void FOnChallengeLostMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeLostMessage, FGSChallengeLostMessage ChallengeLostMessage) \
{ \
	GSMessageListeners_eventOnChallengeLostMessage_Parms Parms; \
	Parms.ChallengeLostMessage=ChallengeLostMessage; \
	OnChallengeLostMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_65_DELEGATE \
struct GSMessageListeners_eventOnChallengeLapsedMessage_Parms \
{ \
	FGSChallengeLapsedMessage ChallengeLapsedMessage; \
}; \
static inline void FOnChallengeLapsedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeLapsedMessage, FGSChallengeLapsedMessage ChallengeLapsedMessage) \
{ \
	GSMessageListeners_eventOnChallengeLapsedMessage_Parms Parms; \
	Parms.ChallengeLapsedMessage=ChallengeLapsedMessage; \
	OnChallengeLapsedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_60_DELEGATE \
struct GSMessageListeners_eventOnChallengeJoinedMessage_Parms \
{ \
	FGSChallengeJoinedMessage ChallengeJoinedMessage; \
}; \
static inline void FOnChallengeJoinedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeJoinedMessage, FGSChallengeJoinedMessage ChallengeJoinedMessage) \
{ \
	GSMessageListeners_eventOnChallengeJoinedMessage_Parms Parms; \
	Parms.ChallengeJoinedMessage=ChallengeJoinedMessage; \
	OnChallengeJoinedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_55_DELEGATE \
struct GSMessageListeners_eventOnChallengeIssuedMessage_Parms \
{ \
	FGSChallengeIssuedMessage ChallengeIssuedMessage; \
}; \
static inline void FOnChallengeIssuedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeIssuedMessage, FGSChallengeIssuedMessage ChallengeIssuedMessage) \
{ \
	GSMessageListeners_eventOnChallengeIssuedMessage_Parms Parms; \
	Parms.ChallengeIssuedMessage=ChallengeIssuedMessage; \
	OnChallengeIssuedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_50_DELEGATE \
struct GSMessageListeners_eventOnChallengeExpiredMessage_Parms \
{ \
	FGSChallengeExpiredMessage ChallengeExpiredMessage; \
}; \
static inline void FOnChallengeExpiredMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeExpiredMessage, FGSChallengeExpiredMessage ChallengeExpiredMessage) \
{ \
	GSMessageListeners_eventOnChallengeExpiredMessage_Parms Parms; \
	Parms.ChallengeExpiredMessage=ChallengeExpiredMessage; \
	OnChallengeExpiredMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_45_DELEGATE \
struct GSMessageListeners_eventOnChallengeDrawnMessage_Parms \
{ \
	FGSChallengeDrawnMessage ChallengeDrawnMessage; \
}; \
static inline void FOnChallengeDrawnMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeDrawnMessage, FGSChallengeDrawnMessage ChallengeDrawnMessage) \
{ \
	GSMessageListeners_eventOnChallengeDrawnMessage_Parms Parms; \
	Parms.ChallengeDrawnMessage=ChallengeDrawnMessage; \
	OnChallengeDrawnMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_40_DELEGATE \
struct GSMessageListeners_eventOnChallengeDeclinedMessage_Parms \
{ \
	FGSChallengeDeclinedMessage ChallengeDeclinedMessage; \
}; \
static inline void FOnChallengeDeclinedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeDeclinedMessage, FGSChallengeDeclinedMessage ChallengeDeclinedMessage) \
{ \
	GSMessageListeners_eventOnChallengeDeclinedMessage_Parms Parms; \
	Parms.ChallengeDeclinedMessage=ChallengeDeclinedMessage; \
	OnChallengeDeclinedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_35_DELEGATE \
struct GSMessageListeners_eventOnChallengeChatMessage_Parms \
{ \
	FGSChallengeChatMessage ChallengeChatMessage; \
}; \
static inline void FOnChallengeChatMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeChatMessage, FGSChallengeChatMessage ChallengeChatMessage) \
{ \
	GSMessageListeners_eventOnChallengeChatMessage_Parms Parms; \
	Parms.ChallengeChatMessage=ChallengeChatMessage; \
	OnChallengeChatMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_30_DELEGATE \
struct GSMessageListeners_eventOnChallengeChangedMessage_Parms \
{ \
	FGSChallengeChangedMessage ChallengeChangedMessage; \
}; \
static inline void FOnChallengeChangedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeChangedMessage, FGSChallengeChangedMessage ChallengeChangedMessage) \
{ \
	GSMessageListeners_eventOnChallengeChangedMessage_Parms Parms; \
	Parms.ChallengeChangedMessage=ChallengeChangedMessage; \
	OnChallengeChangedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_25_DELEGATE \
struct GSMessageListeners_eventOnChallengeAcceptedMessage_Parms \
{ \
	FGSChallengeAcceptedMessage ChallengeAcceptedMessage; \
}; \
static inline void FOnChallengeAcceptedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnChallengeAcceptedMessage, FGSChallengeAcceptedMessage ChallengeAcceptedMessage) \
{ \
	GSMessageListeners_eventOnChallengeAcceptedMessage_Parms Parms; \
	Parms.ChallengeAcceptedMessage=ChallengeAcceptedMessage; \
	OnChallengeAcceptedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_20_DELEGATE \
struct GSMessageListeners_eventOnAchievementEarnedMessage_Parms \
{ \
	FGSAchievementEarnedMessage AchievementEarnedMessage; \
}; \
static inline void FOnAchievementEarnedMessage_DelegateWrapper(const FMulticastScriptDelegate& OnAchievementEarnedMessage, FGSAchievementEarnedMessage AchievementEarnedMessage) \
{ \
	GSMessageListeners_eventOnAchievementEarnedMessage_Parms Parms; \
	Parms.AchievementEarnedMessage=AchievementEarnedMessage; \
	OnAchievementEarnedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}




#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_RPC_WRAPPERS
#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUGSMessageListeners(); \
	friend GAMESPARKS_API class UClass* Z_Construct_UClass_UGSMessageListeners(); \
	public: \
	DECLARE_CLASS(UGSMessageListeners, USceneComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/GameSparks"), NO_API) \
	DECLARE_SERIALIZER(UGSMessageListeners) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_INCLASS \
	private: \
	static void StaticRegisterNativesUGSMessageListeners(); \
	friend GAMESPARKS_API class UClass* Z_Construct_UClass_UGSMessageListeners(); \
	public: \
	DECLARE_CLASS(UGSMessageListeners, USceneComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/GameSparks"), NO_API) \
	DECLARE_SERIALIZER(UGSMessageListeners) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGSMessageListeners(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGSMessageListeners) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGSMessageListeners); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGSMessageListeners); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGSMessageListeners(UGSMessageListeners&&); \
	NO_API UGSMessageListeners(const UGSMessageListeners&); \
public:


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGSMessageListeners(UGSMessageListeners&&); \
	NO_API UGSMessageListeners(const UGSMessageListeners&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGSMessageListeners); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGSMessageListeners); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGSMessageListeners)


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_PRIVATE_PROPERTY_OFFSET
#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_10_PROLOG
#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_PRIVATE_PROPERTY_OFFSET \
	TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_RPC_WRAPPERS \
	TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_INCLASS \
	TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_PRIVATE_PROPERTY_OFFSET \
	TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_INCLASS_NO_PURE_DECLS \
	TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TestGameSparks_Plugins_GameSparks_Source_GameSparks_Private_GSMessageListeners_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
