// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class UBehaviorTree;
class UBlackboardData;
class UAIPerceptionComponent;

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

	/** 이 함수가 필요한가? */
	virtual void OnPerception(AActor* Actor, FAIStimulus Stimuls);

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	UPROPERTY(EditDefaultsOnly, Category = CustomAI)
	UBehaviorTree* BTAsset;
	/** 
	UPROPERTY(EditDefaultsOnly, Category = CustomAI)
	UBlackboardData* BBAsset;
	*/

	UPROPERTY(EditDefaultsOnly, Category = CustomAI)
	UAIPerceptionComponent* AIPerception;


private:


public:
	FORCEINLINE UAIPerceptionComponent* GetAIPerception() const { return AIPerception; }

};
