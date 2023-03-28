#include "Character/Enemy/AI/EnemyAIController.h"
#include "Character/Enemy/EnemyCharacter.h"
#include "Character/PlayerCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AEnemyAIController::AEnemyAIController()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	UAISenseConfig_Sight* SightSense = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSense"));
	SightSense->SightRadius = 1000.f;
	SightSense->LoseSightRadius = 1500.f;
	SightSense->DetectionByAffiliation.bDetectNeutrals = true; // Register한 모두를 찾을수 있게
	AIPerception->ConfigureSense(*SightSense);
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnTargetPerceptionUpdated);
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(InPawn);
	check(EnemyCharacter);
	UBlackboardComponent* BlackboardComp = Blackboard; //ue4 와 달리 Blackboard를 바로 쓰는건 안되고 한번 저장해줘야 되나봄.
	if (UseBlackboard(BBAsset, BlackboardComp))
	{
		RunBehaviorTree(BTAsset);
	}

}


void AEnemyAIController::OnPerception(AActor* Actor, FAIStimulus Stimuls)
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(Actor);
	if (PlayerCharacter == nullptr)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Ssss"));
}

void AEnemyAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(Actor);
	if (PlayerCharacter == nullptr) { return; }

	if (Stimulus.WasSuccessfullySensed())
	{
		UE_LOG(LogTemp, Warning, TEXT("Stimulus Sensed!"));
		Blackboard->SetValueAsObject(TEXT("Target"), PlayerCharacter);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Stimulus"));
		Blackboard->SetValueAsObject(TEXT("Target"), nullptr);
	}
}