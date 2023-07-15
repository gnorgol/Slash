// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "Interfaces/HitInterface.h"
#include "Character/CharacterTypes.h"
#include "Enemy.generated.h"


class UHealthBarComponent;
class UPawnSensingComponent;

UCLASS()
class SLASH_API AEnemy : public ABaseCharacter
{ 
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
	virtual void Tick(float DeltaTime) override;
	/* <IHitInterfaces> */
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void Destroyed() override;
protected:
	
	virtual void BeginPlay() override;
	virtual void Die() override;
	bool InTargetRange(AActor* Target, double Radius);
	void MoveToTarget(AActor* Target);
	AActor* ChoosePatrolTarget();
	virtual void Attack() override;
	virtual void AttackEnd() override;
	virtual bool CanAttack() override;
	virtual void HandleDamage(float DamageAmount) override;

	UFUNCTION()
		void PawnSeen(APawn* Pawn); //Callback for OnPawnSeen in UPawnSensingComponent



	UPROPERTY(BlueprintReadOnly)
	EEnemyState EnemyState = EEnemyState::EES_Patrolling;



public:	

private:

	UPROPERTY(VisibleAnywhere)
	UHealthBarComponent* HealthBarWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AWeapon > WeaponClass;

	UPROPERTY(EditAnywhere)
	double CombatRadius = 800.0f;

	UPROPERTY(EditAnywhere)
	double AttackRadius = 150.0f;

	UPROPERTY(EditAnywhere)
	double PatrolRadius = 200.f;

	FTimerHandle PatrolTimer;

	void PatrolTimerFinished();

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	float PatrolWaitMin = 5.f;
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	float PatrolWaitMax = 10.f;
	/*
	Ai Behavior
	*/
	void InitializeEnemy();
	void HideHealthBar();
	void ShowHealthBar();
	void LoseInterest();
	void StartPatrolling();
	void ChaseTarget();
	bool IsOutSideCombatRadius();
	bool IsOutSideAttackRadius();
	bool IsInsideAttackRadius();
	bool IsChasing();
	bool IsAttacking();
	bool IsDead();
	bool IsEngaged();
	void ClearPatrolTimer();
	void CheckPatrolTarget();
	void CheckCombatTarget();
	void SpawnDefaultWeapon();
	/*
	Combat
	*/
	void StartAttackTimer();
	void ClearAttackTimer();
	FTimerHandle AttackTimer;
	UPROPERTY(EditAnywhere, Category = Combat)
	float AttackMin = 0.5f;
	UPROPERTY(EditAnywhere, Category = Combat)
	float AttackMax = 1.f;

	UPROPERTY(EditAnywhere , Category = Combat)
	float PatrollingSpeed = 125.f;

	UPROPERTY(EditAnywhere, Category = Combat)
	float ChasingSpeed = 300.f;
	UPROPERTY(EditAnywhere, Category = Combat)
	float DeathLifeSpan = 8.f;
	/*
	Navigations
	*/
	UPROPERTY()
	class AAIController* EnemyController;

	// Current Patrol Target
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	AActor* PatrolTarget;

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TArray<AActor*> PatrolPoints;

	/*
	  Components
	*/
	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSensing;
};
