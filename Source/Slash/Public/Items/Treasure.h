// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Treasure.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API ATreasure : public AItem
{
	GENERATED_BODY()

protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
			                                  const FHitResult& SweepResult) override;
private:
	UPROPERTY(EditAnywhere, Category = Sounds)
		USoundBase* PickupSound;
	
};