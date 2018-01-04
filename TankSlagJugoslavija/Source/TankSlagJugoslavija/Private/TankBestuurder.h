// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankBestuurder.generated.h" // Moet als laatste staan

/**
 * 
 */
UCLASS()
class ATankBestuurder : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* VerkrijgBestuurdeTank() const;
	virtual void Tick(float DeltaTime) override;
	void RichtNaarVizier();
	void BeginPlay() override;

	// Geef een parameter terug: WAAR als het het land raakt, anders ONWAAR
	bool VerkrijgRaakLocatie(FVector &UitRaakLocatie) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
		float LijnTraceerOmvang = 1000000; //in centimeters

	bool VerkrijgVectorRaakLocatie(FVector Kijkrichting, FVector &Raaklocatie) const;
	bool VerkrijgKijkRichting(FVector2D SchermLocatie, FVector &KijkRichting) const;
};
