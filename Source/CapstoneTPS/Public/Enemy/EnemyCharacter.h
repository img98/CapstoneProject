// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "EnemyCharacter.generated.h"

class AAIController;
class UBehaviorTree;
/**
 * 
 */
UCLASS()
class CAPSTONETPS_API AEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	virtual void Tick(float DeltaTime);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	AAIController* EnemyController;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
	
private:

};
