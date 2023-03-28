// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Enemy/EnemyCharacter.h"
#include "ShooterEnemy.generated.h"

class UAIPerceptionComponent;
class AEnemyAIController;

UCLASS()
class CAPSTONETPS_API AShooterEnemy : public AEnemyCharacter
{
	GENERATED_BODY()
	
public:
	AShooterEnemy();

protected:
	UPROPERTY()
	AEnemyAIController* EnemyController;


private:


};
