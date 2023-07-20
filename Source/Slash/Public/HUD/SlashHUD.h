// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlashHUD.generated.h"

class USlashOverlay;
class USlashMenuOverlay;

UCLASS()
class SLASH_API ASlashHUD : public AHUD
{
	GENERATED_BODY()
protected:

	virtual void PreInitializeComponents() override;
	

public :


private:

	UPROPERTY(EditDefaultsOnly,Category = Slash)
	TSubclassOf<USlashOverlay> SlashOverlayClass;

	UPROPERTY(EditDefaultsOnly, Category = Slash)
	TSubclassOf<USlashMenuOverlay> SlashMenuOverlayClass;

	UPROPERTY()
	USlashOverlay* SlashOverlay;

	UPROPERTY()
	USlashMenuOverlay* SlashMenuOverlay;

public:
	FORCEINLINE USlashOverlay* GetSlashOverlay() const { return SlashOverlay; }
	FORCEINLINE USlashMenuOverlay* GetSlashMenuOverlay() const { return SlashMenuOverlay; }

};
