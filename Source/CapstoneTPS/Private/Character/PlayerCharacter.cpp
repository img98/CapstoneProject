// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Inputs
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"

APlayerCharacter::APlayerCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(SpringArm);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		InputSubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (InputSubSystem)
		{
			InputSubSystem->AddMappingContext(MovementModeContext, 0);
		}
	}
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	}
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	//FRotator Rotation;
	//FVector ForwardDirection;
	//FVector RightDirection;

	const FRotator Rotation = FRotator{ 0.f, Controller->GetControlRotation().Yaw, 0.f };
	const FVector ForwardDirection = FVector(FRotationMatrix(Rotation).GetUnitAxis(EAxis::X));
	const FVector RightDirection = FVector(FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y));

	AddMovementInput(ForwardDirection, MovementVector.Y);
	AddMovementInput(RightDirection, MovementVector.X);
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerPitchInput(LookAxisVector.Y);
	AddControllerYawInput(LookAxisVector.X);
}