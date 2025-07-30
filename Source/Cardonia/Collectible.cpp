// Fill out your copyright notice in the Description page of Project Settings.
#include "Collectible.h"
#include "BaseCharacter.h"


// Sets default values
ACollectible::ACollectible()
{
	PrimaryActorTick.bCanEverTick = true;
    ItemName = TEXT("Unnamed Collectible");
    ItemWeight = 1.0f;
    ItemValue = 10;
    ItemMesh = nullptr;
}

// Called when the game starts or when spawned
void ACollectible::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectible::OnInteract_Implementation()
{
	if (GEngine)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Interacted with a Collectible!"));
	}
}

void ACollectible::OnGrab_Implementation(ABaseCharacter* GrabbingCharacter)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, TEXT("Grabbed a Collectible!"));
    }

    if (GrabbingCharacter && GrabbingCharacter->InventoryComponent)
    {
        UInventoryItem* NewItem = NewObject<UInventoryItem>(GrabbingCharacter->InventoryComponent);
        NewItem->ItemName = ItemName;
        NewItem->ItemWeight = ItemWeight;
        NewItem->ItemValue = ItemValue;
        NewItem->ItemMesh = ItemMesh;

        // Add the item to the character's inventory
        GrabbingCharacter->InventoryComponent->AddItem(NewItem);

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, TEXT("Item added to inventory!"));
        }

        if (IsValid(this)) {
			// Destroy the collectible
			Destroy();
        }
        else
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Red, TEXT("Collectible is already invalid!"));
            }
        }
    }
    else {
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Red, TEXT("No inventory component found!"));
		}
    }
}


EInteractableType ACollectible::GetInteractableType_Implementation() const
{
	return EInteractableType::Collectible;
}

