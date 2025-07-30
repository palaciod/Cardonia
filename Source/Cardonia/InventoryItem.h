// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItem.generated.h"

/**
 * an item that can be stored in an inventory
 */
UCLASS(Blueprintable)
class CARDONIA_API UInventoryItem : public UObject
{
	GENERATED_BODY()

public:
	// Default constructor
	UInventoryItem();

	// The name of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString ItemName;

	// The weight of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float ItemWeight;

	// The value of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 ItemValue;

	// The static mesh of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UStaticMesh* ItemMesh;
};
