// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

// Inputs
class UEnhancedInputLocalPlayerSubsystem;
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class CAPSTONETPS_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	APlayerCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputMappingContext* MovementModeContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UCameraComponent* MainCamera;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

private:
	UEnhancedInputLocalPlayerSubsystem* InputSubSystem;

};
