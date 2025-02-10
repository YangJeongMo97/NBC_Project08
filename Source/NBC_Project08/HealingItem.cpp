// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"
#include "NBC_Project08Character.h"

AHealingItem::AHealingItem()
{
	HealAmount = 20;
	ItemType = "Healing";
}

void AHealingItem::ActiveItem(AActor* Activator)
{
    if (Activator && Activator->ActorHasTag("Player"))
    {
        if (ANBC_Project08Character* PlayerCharacter = Cast<ANBC_Project08Character>(Activator))
        {
            PlayerCharacter->AddHealth(HealAmount);
        }

        SpawnParticle();
        PlaySound();

        DestroyItem();
    }
}
