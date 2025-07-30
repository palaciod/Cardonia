#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CARDONIA_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Function to add an item to the inventory
	void AddItem(UInventoryItem* Item);

	// Function to remove an item from the inventory
	void RemoveItem(UInventoryItem* Item);

	// Function to get all items in the inventory
	UFUNCTION(BlueprintPure, Category = "Inventory")
	const TArray<UInventoryItem*>& GetItems() const;

	// Function to print the contents of the inventory
	void PrintInventoryContents() const;

private:
	// Array to store the items in the inventory
	UPROPERTY()
	TArray<UInventoryItem*> Items;
};