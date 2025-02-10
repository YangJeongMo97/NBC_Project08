// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "MineItem.generated.h"

/**
 * 
 */
UCLASS()
class NBC_PROJECT08_API AMineItem : public AItemBase
{
	GENERATED_BODY()

public:
    AMineItem();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
    USphereComponent* ExplosionCollision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    float ExplosionDelay;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    float ExplosionRadius;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    float ExplosionDamage;

    FTimerHandle ExplosionTimerHandle;

    virtual void ActiveItem(AActor* Activator) override;

    void Explode();
};
