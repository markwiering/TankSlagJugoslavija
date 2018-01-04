// Fill out your copyright notice in the Description page of Project Settings.

#include "TankSlagJugoslavija.h"
#include "TankBestuurder.h"


// Called every frame
void ATankBestuurder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RichtNaarVizier();
	//UE_LOG(LogTemp, Warning, TEXT("Eer Servië!"));
}

void ATankBestuurder::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("Tankbestuurder meldt zich!\n"));
	auto BestuurdeTank = VerkrijgBestuurdeTank();
	if (!BestuurdeTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Wa... Waar is mijn tank?!?!?!\n"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tankbestuurder zit in %s!"), *BestuurdeTank->GetName());
	}
}

ATank* ATankBestuurder::VerkrijgBestuurdeTank() const
{
	return Cast<ATank>(GetPawn());	
}

void ATankBestuurder::RichtNaarVizier()
{
	if (! VerkrijgBestuurdeTank()) { return; }
	FVector RaakLocatie; // 

	if (VerkrijgRaakLocatie(RaakLocatie)) // Lijntracering
	{
		//UE_LOG(LogTemp, Warning, TEXT("Raaklocatie: %s"), *RaakLocatie.ToString())
		VerkrijgBestuurdeTank()->RichtOp(RaakLocatie);
		// TODO: vertel de tank om op dit punt te richten
	}
}

bool ATankBestuurder::VerkrijgRaakLocatie(FVector &UitRaakLocatie) const
{
	// Vind het vizier
	int32 uitkijkGrootteX, uitkijkGrootteY; GetViewportSize(uitkijkGrootteX, uitkijkGrootteY);
	auto SchermLocatie=FVector2D(uitkijkGrootteX * CrosshairXLocation, uitkijkGrootteY * CrosshairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("Schermlocatie: %s"), *SchermLocatie.ToString());

	// Deprojectie
	FVector CameraWereldLocatie, WereldRichting;
	if (VerkrijgKijkRichting(SchermLocatie, WereldRichting))
	{
		VerkrijgVectorRaakLocatie(WereldRichting, UitRaakLocatie);
		//UE_LOG(LogTemp, Warning, TEXT("Kijklocatie: %s"), *WereldRichting.ToString())
	}
	// Lijntracering en zien wat er geraakt wordt
	return true;
}

bool ATankBestuurder::VerkrijgVectorRaakLocatie(FVector KijkRichting, FVector &RaakLocatie) const
{
	FHitResult RaakResultaat;
	auto startPlek = PlayerCameraManager->GetCameraLocation();
	auto eindPlek = startPlek + (KijkRichting * LijnTraceerOmvang);
	if (GetWorld()->LineTraceSingleByChannel(RaakResultaat, 
		startPlek, 
		eindPlek, 
		ECollisionChannel::ECC_Visibility))
	{
		RaakLocatie = RaakResultaat.Location;
			return true;
	}
	else
	{
		RaakLocatie = FVector(0);
		return false;
	}
}

bool ATankBestuurder::VerkrijgKijkRichting(FVector2D SchermLocatie, FVector &KijkRichting) const
{
	FVector CameraWereldLocatie;
	return DeprojectScreenPositionToWorld(SchermLocatie.X, SchermLocatie.Y, CameraWereldLocatie, KijkRichting);
}