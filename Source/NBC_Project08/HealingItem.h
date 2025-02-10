// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "HealingItem.generated.h"

/**
 * 
 */
UCLASS()
class NBC_PROJECT08_API AHealingItem : public AItemBase
{
	GENERATED_BODY()

public:
	AHealingItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 HealAmount;

	virtual void ActiveItem(AActor* Activator) override;
};
