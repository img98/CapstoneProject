// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Enemy/EnemyCharacter.h"
#include "ShooterEnemy.generated.h"

class UAIPerceptionComponent;

UCLASS()
class CAPSTONETPS_API AShooterEnemy : public AEnemyCharacter
{
	GENERATED_BODY()
	
public:
	AShooterEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom)
	UAIPerceptionComponent* AIPerception;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

protected:

private:


};
