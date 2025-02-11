// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "CoinItem.generated.h"

/**
 * 
 */
UCLASS()
class NBC_PROJECT08_API ACoinItem : public AItemBase
{
	GENERATED_BODY()
	
public:
	ACoinItem();

	virtual void ActiveItem(AActor* Activator) override;

	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 PointValue;
};
