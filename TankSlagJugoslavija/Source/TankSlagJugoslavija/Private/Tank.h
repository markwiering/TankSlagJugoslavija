// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKSLAGJUGOSLAVIJA_API ATank : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	void RichtOp(FVector RaakLocatie);

private:
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
