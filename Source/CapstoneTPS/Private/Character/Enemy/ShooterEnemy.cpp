// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/ShooterEnemy.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AShooterEnemy::AShooterEnemy()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	//�׷��� ����ٰ� ������Ƽ �����, ���߿� �޸� �������� �ʳ�? UPROPERTY����ߵɰŰ�����
	UAISenseConfig_Sight* SightSense = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSense"));
	SightSense->SightRadius = 1000.f;
	SightSense->LoseSightRadius = 1500.f;
	SightSense->DetectionByAffiliation.bDetectNeutrals = true; // Register�� ��θ� ã���� �ְ�
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