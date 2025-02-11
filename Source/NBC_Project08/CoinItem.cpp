// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinItem.h"
#include "Engine/World.h"
#include "SpartaGameState.h"
#include "SpartaGameInstance.h"

ACoinItem::ACoinItem()
{
	PrimaryActorTick.bCanEverTick = true;

	PointValue = 0;
	ItemType = "DefaultCoin";
}

void ACoinItem::ActiveItem(AActor* Activator)
{
    if (Activator && Activator->ActorHasTag("Player"))
    {
		if (UWorld* World = GetWorld())
		{
			if (ASpartaGameState* GameState = World->GetGameState<ASpartaGameState>())
			{
				GameState->AddScore(PointValue);
				GameState->OnCoinCollected();
			}
		}

		SpawnParticle();
		PlaySound();

        DestroyItem();
    }
}

void ACoinItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator CurrentRotate = GetActorRotation();

	SetActorRotation(CurrentRotate + FRotator(0.f, 180.f * DeltaTime, 0.f));
}
