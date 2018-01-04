// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "KI_TankBestuurder.generated.h"

/**
 * 
 */
UCLASS()
class AKI_TankBestuurder : public AAIController
{
	GENERATED_BODY()
public:
	ATank* VerkrijgBestuurdeTank() const;
	ATank* VerkrijgSpelersTank() const;
	void BeginPlay() override;
};
