#pragma once

#include "CoreMinimal.h"
#include "CardoniaCharacter.h"
#include "Species.h"
#include "Camera/CameraComponent.h"
#include "MyInteractableInterface.h"
#include "InventoryComponent.h"
#include "BaseCharacter.generated.h"

/**
 *
 */
UCLASS()
class CARDONIA_API ABaseCharacter : public ACardoniaCharacter, public IMyInteractableInterface
{
	GENERATED_BODY()

public:
	// Constructor
	ABaseCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	FSpeciesInfo SpeciesInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	float CurrentHealth;

	// Method to convert FSpeciesInfo to a string
	UFUNCTION(BlueprintCallable, Category = "Character")
	FString GetSpeciesInfoAsString() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	AActor* CurrentFocusedActor;

	// Implement the Interact function from the interface
	virtual void OnInteract_Implementation() override;

	// Inventory component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	UInventoryComponent* InventoryComponent;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UInventoryComponent* GetInventoryComponent() const { return InventoryComponent; }

	// Input Action for Grab
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* GrabAction;

	// Input Action for Attack
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* AttackAction;

	UFUNCTION(BlueprintCallable, Category = "Input")
	void AttackKeyPressed();


	// Function to handle the grab action
	UFUNCTION(BlueprintCallable, Category = "Input")
	void GrabKeyPressed();
	virtual void OnAttack_Implementation(ABaseCharacter* CurrentFocusedActor) override;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	virtual void OnAttackRecieved_Implementation(float DamageAmount, UPrimitiveComponent* OverlappedComponent, AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void OnAttackColliderOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void AttackRecievedFunction(float DamageAmount, UPrimitiveComponent* OverlappedComponent, AActor* OtherActor);

	UFUNCTION(BlueprintCallable, Category = "Character")
	void ShowCurrentHealth();

private:
	void PerformLineTrace();
	//void GrabKeyPressed();
};