// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    SetRootComponent(Scene);

    Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));

    Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

    Collision->SetupAttachment(Scene);

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(Collision);
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
    Collision->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnItemOverlap);
    Collision->OnComponentEndOverlap.AddDynamic(this, &AItemBase::OnItemEndOverlap);
}

void AItemBase::OnItemOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->ActorHasTag("Player"))
    {
        ActiveItem(OtherActor);
    }
}

void AItemBase::OnItemEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AItemBase::ActiveItem(AActor* Activator)
{

}

FName AItemBase::GetItemName() const
{
	return ItemType;
}

void AItemBase::SpawnParticle()
{
    if (ParticleEffect)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleEffect, GetActorLocation());
    }
}

void AItemBase::PlaySound()
{
    if (SoundEffect)
    {
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), SoundEffect, GetActorLocation());
    }
}

void AItemBase::DestroyItem()
{
	Destroy();
}
