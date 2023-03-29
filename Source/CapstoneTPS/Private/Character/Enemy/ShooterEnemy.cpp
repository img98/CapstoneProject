// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/ShooterEnemy.h"
#include "Perception/AIPerceptionComponent.h"
#include "Character/Enemy/AI/EnemyAIController.h"

AShooterEnemy::AShooterEnemy()
{
	AIControllerClass = AEnemyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}
