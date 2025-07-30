#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyInteractableInterface.generated.h"

UENUM(BlueprintType)
enum class EInteractableType : uint8
{
    None        UMETA(DisplayName = "None"),
    Character   UMETA(DisplayName = "Character"),
    Collectible UMETA(DisplayName = "Collectible"),
    Door        UMETA(DisplayName = "Door"),
    // Add more as needed: Vendor, Puzzle, Container, etc.
};

// This macro sets up reflection for the interface so it can be recognized by UE4/UE5
UINTERFACE(MinimalAPI, Blueprintable)
class UMyInteractableInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * The actual interface class that will be inherited by other classes.
 */
class CARDONIA_API IMyInteractableInterface
{
    GENERATED_BODY()

public:
    // Marking it BlueprintNativeEvent means you can override it in both C++ and Blueprint.
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    void OnInteract();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    void OnGrab(ABaseCharacter* CurrentFocusedActor);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    void OnAttack(ABaseCharacter* SelfCharacter);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    void OnAttackRecieved(float DamageAmount, UPrimitiveComponent* OverlappedComponent, AActor* OtherActor);

    // Identify the type of interactable object
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
    EInteractableType GetInteractableType() const;
    virtual EInteractableType GetInteractableType_Implementation() const { return EInteractableType::None; }

    // Optional: CanInteract() function
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")

    bool CanInteract() const;
    virtual bool CanInteract_Implementation() const { return true; }
};