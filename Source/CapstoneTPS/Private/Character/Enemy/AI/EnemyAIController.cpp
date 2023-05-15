#include "Character/Enemy/AI/EnemyAIController.h"
#include "Character/Enemy/EnemyCharacter.h"
#include "Character/PlayerCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"

AEnemyAIController::AEnemyAIController()
{
	/** SetUp AIPerception*/
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));

	UAISenseConfig_Sight* SightSense = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSense"));
	SightSense->SightRadius = 600.f;
	SightSense->LoseSightRadius = 1000.f;
	SightSense->PeripheralVisionAngleDegrees = 60.f;
	SightSense->DetectionByAffiliation.bDetectNeutrals = true; // Register�� ��θ� ã���� �ְ�
	AIPerception->ConfigureSense(*SightSense);

	UAISenseConfig_Hearing* HearingSense = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingSense"));
	HearingSense->HearingRange = 1000.f;
	HearingSense->DetectionByAffiliation.bDetectNeutrals = true;
	HearingSense->DetectionByAffiliation.bDetectFriendlies = true; //�Ʊ��� �Ѽ��� ���ؿ�ĵ�Ҹ��� �������
	AIPerception->ConfigureSense(*HearingSense);

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
	UBlackboardComponent* BlackboardComp = Blackboard; //ue4 �� �޸� Blackboard�� �ٷ� ���°� �ȵǰ� �ѹ� ��������� �ǳ���.
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

}

void AEnemyAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (!Stimulus.WasSuccessfullySensed()) return;
	TSubclassOf<UAISense> SenseClass = UAIPerceptionSystem::GetSenseClassForStimulus(GetWorld(), Stimulus);
	FName SenseName = SenseClass->GetFName();
	UE_LOG(LogTemp, Warning, TEXT("Get SenseClass for Stimulus [%s]"), *SenseName.ToString());

	//TODO: �νĵ� ������ ���� ���� �۵�
	if (APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(Actor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Stimulus Sensed! : [%s]"), *PlayerCharacter->GetName());
		Blackboard->SetValueAsObject(TEXT("Target"), PlayerCharacter);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Stimulus"));
		Blackboard->SetValueAsObject(TEXT("Target"), nullptr);
	}
}