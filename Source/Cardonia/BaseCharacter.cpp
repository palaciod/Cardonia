#include "BaseCharacter.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"
#include "EnhancedInputComponent.h" // Include for Enhanced Input
#include "EnhancedInputSubsystems.h" // Include for Enhanced Input
#define TRACE_GRABBER ECC_GameTraceChannel1


// Constructor
ABaseCharacter::ABaseCharacter()
{
    // Set default values
    CharacterName = "DefaultName";
    SpeciesInfo = FSpeciesInfo();
    MaxHealth = 100.0f;
    CurrentHealth = MaxHealth;
    InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
    static ConstructorHelpers::FObjectFinder<UInputAction> IA_Grab(TEXT("/Game/Input/IA_Grab"));
	static ConstructorHelpers::FObjectFinder< UInputAction> IA_Attack(TEXT("/Game/Input/IA_Attack"));
    if (IA_Grab.Succeeded())
    {
        GrabAction = IA_Grab.Object;
    }
	if (IA_Attack.Succeeded())
	{
		AttackAction = IA_Attack.Object;
	}
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Perform line trace every frame
    PerformLineTrace();
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind input functions here
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(GrabAction, ETriggerEvent::Started, this, &ABaseCharacter::GrabKeyPressed);
        EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &ABaseCharacter::AttackKeyPressed);
        PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
        PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);
    }
}

void ABaseCharacter::ShowCurrentHealth()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Purple,
            FString::Printf(TEXT("Actor: %s | Character: %s | Current Health: %f"),
                *GetName(), *CharacterName, CurrentHealth));
    }
}


void ABaseCharacter::MoveForward(float Value)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Yellow, FString::Printf(TEXT("MoveForward called with value: %f"), Value));
    }

    if (Controller && Value != 0.0f)
    {
        // Find out which way is forward
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // Get forward vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void ABaseCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        // Find out which way is right
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // Get right vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}


void ABaseCharacter::PerformLineTrace()
{   
    FVector SecondStart = GetActorLocation() + FVector(0, 0, 50);
    //FVector Start = GetFollowCamera()->GetComponentLocation();
    FVector ForwardVector = GetFollowCamera()->GetForwardVector();
    FVector End = SecondStart + (ForwardVector * 200.f);
    FHitResult HitResult;

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(this);

    // Perform the line trace
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, SecondStart, End, ECC_GameTraceChannel1, CollisionParams);

    // Draw debug line
    DrawDebugLine(GetWorld(), SecondStart, End, FColor::Green, false, 1, 0, 1);

    if (bHit)
    {
        // Print the name of the hit actor to the screen
        if (GEngine)
        {
            AActor* HitActor = HitResult.GetActor();
            
            if (HitActor)
            {
                ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(HitActor);
                if (HitActor->GetClass()->ImplementsInterface(UMyInteractableInterface::StaticClass()))
                {
                    CurrentFocusedActor = HitActor;
                    IMyInteractableInterface::Execute_OnInteract(HitActor);
                }
                else {
                    CurrentFocusedActor = nullptr;
                }
            }
            else {
                
            }
        }
    }
    else {
        // Print that nothing was hit
        CurrentFocusedActor = nullptr;
    }
}

void ABaseCharacter::GrabKeyPressed()
{   
    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Pressing X"));
        return;
    }


    if (CurrentFocusedActor &&
        CurrentFocusedActor->GetClass()->ImplementsInterface(UMyInteractableInterface::StaticClass()))
    {
        // If the actor is collectible
        IMyInteractableInterface::Execute_OnGrab(CurrentFocusedActor, this);
        // Print the contents of the inventory
        if (InventoryComponent)
        {
            InventoryComponent->PrintInventoryContents();
        }
    }
    else {
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Purple, TEXT("No actor to grab!"));
		}
    }
}

void ABaseCharacter::AttackKeyPressed()
{
    OnAttack_Implementation(this);
}


// Function not being used anymore since we can just use the OnAttack_Implentation function
void ABaseCharacter::AttackRecievedFunction(float DamageAmount, UPrimitiveComponent* OverlappedComponent, AActor* OtherActor)
{
	// Call the interface function
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Red,
			FString::Printf(TEXT("Hit %s with attack!"), *OtherActor->GetName()));
	}
	// Call the interface function
	OnAttackRecieved_Implementation(DamageAmount, OverlappedComponent, OtherActor);
}

FString ABaseCharacter::GetSpeciesInfoAsString() const
{
    FString SpeciesTypeString = StaticEnum<ESpeciesType>()->GetValueAsString(SpeciesInfo.SpeciesType);
    FString HumanSubTypeString = StaticEnum<HumanSpeciesSubType>()->GetValueAsString(SpeciesInfo.HumanSubType);
    FString ElfSubTypeString = StaticEnum<ElfSpeciesSubType>()->GetValueAsString(SpeciesInfo.ElfSubType);
    FString AnimalSubTypeString = StaticEnum<AnimalSpeciesSubType>()->GetValueAsString(SpeciesInfo.AnimalSubType);

    return FString::Printf(TEXT("%s-%s-%s-%s"), *SpeciesTypeString, *HumanSubTypeString, *ElfSubTypeString, *AnimalSubTypeString);
}

void ABaseCharacter::OnInteract_Implementation()
{
    if (GEngine)
    {
        //GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Interacted with BaseCharacter!"));
    }
}

void ABaseCharacter::OnAttack_Implementation(ABaseCharacter* SelfCharacter)
{
    // Handle character death
    if (GEngine)
    {
        //GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, TEXT("Character is attacking!"));
    }
}

void ABaseCharacter::OnAttackRecieved_Implementation(float DamageAmount, UPrimitiveComponent* OverlappedComponent, AActor* OtherActor)
{
	
	// Get other character health 
    ABaseCharacter* OtherCharacter = Cast<ABaseCharacter>(OtherActor);
    if (OtherCharacter) {
		// Apply damage
		OtherCharacter->CurrentHealth -= DamageAmount;
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Red,
				FString::Printf(TEXT("Hit %s with attack!"), *OtherCharacter->CharacterName));
		}
		// Check if the character is dead
		if (OtherCharacter->CurrentHealth <= 0)
		{
			// Handle character death
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Red,
					TEXT("Character is dead!"));
			}
		}
    }
    else {
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Red,
				TEXT("Hit non-character!"));
		}
    }

}

void ABaseCharacter::OnAttackColliderOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    // Don't damage self
    if (OtherActor == this)
    {
        return;
    }
}
