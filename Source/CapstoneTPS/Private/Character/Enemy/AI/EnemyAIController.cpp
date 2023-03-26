#include "Character/Enemy/AI/EnemyAIController.h"
#include "Character/Enemy/EnemyCharacter.h"
#include "Character/PlayerCharacter.h"

AEnemyAIController::AEnemyAIController()
{

}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AEnemyAIController::OnPerception(AActor* Actor, FAIStimulus Stimuls)
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(Actor);
	if (PlayerCharacter == nullptr)
	{
		return;
	}
}