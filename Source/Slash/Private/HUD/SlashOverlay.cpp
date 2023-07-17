// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void USlashOverlay::SetHealthPercent(float Percent)
{
	
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetStaminaPercent(float Percent)
{
	if (StaminaProgressBar)
	{
		StaminaProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetGold(int32 Gold)
{
	if (GoldText)
	{
		GoldText->SetText(FText::FromString(FString::FromInt(Gold)));
	}
}

void USlashOverlay::SetSoul(int32 Soul)
{
	if (SoulText)
	{
		SoulText->SetText(FText::FromString(FString::FromInt(Soul)));
	}
}

void USlashOverlay::SetHelpText(const FText& Text)
{
	if (HelpText)
	{
		HelpText->SetText(Text);
	}
}

void USlashOverlay::SetHelpTextVisibility(bool bVisible)
{
	if (HelpText)
	{
		HelpText->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	}
}
