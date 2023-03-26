// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "EnemyAIController.generated.h"

/**
 *
 */
UCLASS()
class CAPSTONETPS_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

	public:
	AEnemyAIController();

protected:
	UPROPERTY(VisibleAnywhere)
	UAIPerceptionComponent* AIPerceptionComponent;

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	virtual void OnPerception(AActor* Actor, FAIStimulus Stimuls);

private:


};
