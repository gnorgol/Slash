// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Health.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API AHealth : public AItem
{
	GENERATED_BODY()
protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:
	UPROPERTY(EditAnywhere, Category = "Soul Properties")
		int32 HealthValue;
public:
	FORCEINLINE int32 GetHealthValue() const { return HealthValue; }
	FORCEINLINE void SetHealthValue(int32 Value) { HealthValue = Value; }
};
