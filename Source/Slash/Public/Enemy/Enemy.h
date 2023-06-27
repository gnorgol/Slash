// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Enemy.generated.h"

class UAnimMontage;

UCLASS()
class SLASH_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetHit(const FVector& ImpactPoint) override;

protected:
	
	virtual void BeginPlay() override;

	/*
	Play Montage function
	*/
	void PlayHitReactMontage(const FName SectionName);

public:	

private:
	/*
	Animation Montage
	*/
	UPROPERTY(EditDefaultsOnly, Category = Montages)
		UAnimMontage* HitReactMontage;
	
};
