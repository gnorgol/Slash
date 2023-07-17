// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlashOverlay.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API USlashOverlay : public UUserWidget
{
	GENERATED_BODY()
	


public:
	void SetHealthPercent(float Percent);
	void SetStaminaPercent(float Percent);
	void SetGold(int32 Gold);
	void SetSoul(int32 Soul);
	void SetHelpText(const FText& Text);
	void SetHelpTextVisibility(bool bVisible);

private:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthProgressBar;

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* StaminaProgressBar;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* GoldText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* SoulText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HelpText;
};
