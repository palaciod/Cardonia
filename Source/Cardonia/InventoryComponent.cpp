#include "InventoryComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInventoryComponent::AddItem(UInventoryItem* Item)
{
	if (Item)
	{
		Items.Add(Item);
	}
}

void UInventoryComponent::RemoveItem(UInventoryItem* Item)
{
	if (Item)
	{
		Items.Remove(Item);
	}
}

const TArray<UInventoryItem*>& UInventoryComponent::GetItems() const
{
	return Items;
}

void UInventoryComponent::PrintInventoryContents() const
{
	if (GEngine)
	{
		for (const UInventoryItem* Item : Items)
		{
			if (Item)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Item: %s, Weight: %f, Value: %d"), *Item->ItemName, Item->ItemWeight, Item->ItemValue));
			}
		}
	}
}