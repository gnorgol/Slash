#pragma once

//Game States
UENUM(BlueprintType)
enum class EGameState
{
	EGS_Menu UMETA(DisplayName = "Menu"),
	EGS_Paused UMETA(DisplayName = "Paused"),
	EGS_InGame UMETA(DisplayName = "InGame"),
	EGS_GameOver UMETA(DisplayName = "GameOver"),
	EGS_Credits UMETA(DisplayName = "Credits")
};