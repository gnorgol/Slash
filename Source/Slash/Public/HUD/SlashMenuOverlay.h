// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlashMenuOverlay.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API USlashMenuOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
		class UButton* PlayButton;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* PlayText;
	UPROPERTY(meta = (BindWidget))
		class UButton* CreditButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* QuitButton;
};
