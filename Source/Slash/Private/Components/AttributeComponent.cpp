// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AttributeComponent.h"


UAttributeComponent::UAttributeComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

}



void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();


	
}

void UAttributeComponent::ReceiveDamage(float DamageAmount)
{
	Health = FMath::Clamp(Health - DamageAmount, 0.f, MaxHealth);
}

float UAttributeComponent::GetHealthPercent()
{
	return Health / MaxHealth;
}

bool UAttributeComponent::IsAlive()
{
	return Health > 0.f;
}

void UAttributeComponent::AddGold(int32 Amount)
{
	Gold += Amount;
}

void UAttributeComponent::AddSouls(int32 Amount)
{
	Souls += Amount;
}


void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

