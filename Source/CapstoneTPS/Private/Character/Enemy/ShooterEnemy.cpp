// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/ShooterEnemy.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AShooterEnemy::AShooterEnemy()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	//그런데 여기다가 프로퍼티 만들면, 나중에 메모리 누수나지 않나? UPROPERTY해줘야될거같은데
	UAISenseConfig_Sight* SightSense = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSense"));
	SightSense->SightRadius = 1000.f;
	SightSense->LoseSightRadius = 1500.f;
	SightSense->DetectionByAffiliation.bDetectNeutrals = true; // Register한 모두를 찾을수 있게
	AIPerception->ConfigureSense(*SightSense);

	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AShooterEnemy::OnTargetPerceptionUpdated);
}

void AShooterEnemy::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		UE_LOG(LogTemp, Warning, TEXT("Stimulus Sensed!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Stimulus"));
	}
}