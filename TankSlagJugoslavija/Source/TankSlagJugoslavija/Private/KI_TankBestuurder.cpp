// Fill out your copyright notice in the Description page of Project Settings.

#include "TankSlagJugoslavija.h"
#include "KI_TankBestuurder.h"


void AKI_TankBestuurder::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("Tankbestuurder meldt zich!\n"));
	auto SpelersTank = VerkrijgSpelersTank();
	auto BestuurdeTank = VerkrijgBestuurdeTank();
	/*if (!BestuurdeTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Kunstmatige tankbestuurder is zijn tank kwijt!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Kunstmatige tankbestuurder zit in %s!"),
			*BestuurdeTank->GetName());
	}*/

	if (!SpelersTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Kunstmatige tankbestuurder is jou kwijt!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Kunstmatige tankbestuurder ziet jou: %s!"),
			*SpelersTank->GetName());
	}
}

ATank* AKI_TankBestuurder::VerkrijgBestuurdeTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* AKI_TankBestuurder::VerkrijgSpelersTank() const
{
	auto SpelersPion = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!SpelersPion) { return nullptr; }
	return Cast<ATank>(SpelersPion);
}