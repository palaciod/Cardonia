// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyInteractableInterface.h"
#include "InventoryItem.h"
#include "Collectible.generated.h"

UCLASS()
class CARDONIA_API ACollectible : public AActor, public IMyInteractableInterface
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties
	ACollectible();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Implement the Interact function from the interface
	virtual void OnInteract_Implementation() override;
	// Implement the Grab function from the interface
	virtual void OnGrab_Implementation(ABaseCharacter* CurrentFocusedActor);
	// Implement the GetInteractableType function from the interface
	virtual EInteractableType GetInteractableType_Implementation() const override;
	// Store Inventory Item Data

	// Editable inventory properties directly inside Collectible
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	float ItemWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 ItemValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UStaticMesh* ItemMesh;

};
