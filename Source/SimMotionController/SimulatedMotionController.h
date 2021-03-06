// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MotionControllerComponent.h"
#include "SimulatedMotionController.generated.h"

/**
 * 
 */
UCLASS()
class SIMMOTIONCONTROLLER_API USimulatedMotionController : public UMotionControllerComponent
{
	GENERATED_BODY()

public:
	USimulatedMotionController();
	void TranslateController(FVector TranslationVector);
	void RotateController(FRotator RotationRotator);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	void ToggleMoveRight();
	void ToggleMoveLeft();
	void ToggleMoveForward();
	void ToggleMoveBack();
	void ToggleMoveUp();
	void ToggleMoveDown();

	void ToggleXPositiveRotation();
	void ToggleYPositiveRotation();
	void ToggleZPositiveRotation();
	
	void ToggleXNegativeRotation();
	void ToggleYNegativeRotation();
	void ToggleZNegativeRotation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion Simulation", meta = (AllowPrivateAccess = "true"))
	bool ShouldBeSimulated;

private:
	FVector ControllerPosition, TranslationSpeedVector;
	FRotator ControllerOrientation, RotationSpeedRotator;
	bool ShouldMoveLeft, ShouldMoveRight, ShouldMoveForward, ShouldMoveBack, ShouldMoveUp, ShouldMoveDown;
	bool ShouldRotateAroundXPositive, ShouldRotateAroundYPositive, ShouldRotateAroundZPositive;
	bool ShouldRotateAroundXNegative, ShouldRotateAroundYNegative, ShouldRotateAroundZNegative;

	bool PollControllerState(FVector& Position, FRotator& Orientation);

};
