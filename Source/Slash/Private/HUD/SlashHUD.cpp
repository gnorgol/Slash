// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashHUD.h"
#include "HUD/SlashOverlay.h"
#include "HUD/SlashMenuOverlay.h"
#include "Components/Button.h"


void ASlashHUD::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController && SlashOverlayClass)
		{
			SlashOverlay = CreateWidget<USlashOverlay>(PlayerController, SlashOverlayClass);
			//SlashOverlay->AddToViewport();
			SlashMenuOverlay = CreateWidget<USlashMenuOverlay>(PlayerController, SlashMenuOverlayClass);			
			SlashMenuOverlay->AddToViewport();
			
			PlayerController->bShowMouseCursor = true;
		}
	}
}





