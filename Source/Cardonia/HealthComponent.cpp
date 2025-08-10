// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; // We don't need to tick for health

	// Initialize health values
	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// Ensure CurrentHealth is properly initialized
	CurrentHealth = MaxHealth;
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Health component doesn't need to tick
}

void UHealthComponent::SetCurrentHealth(float NewHealth)
{
	float OldHealth = CurrentHealth;
	CurrentHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
	
	// Check for death
	if (CurrentHealth <= 0.0f && OldHealth > 0.0f)
	{
		if (GEngine)
		{
			AActor* Owner = GetOwner();
			FString OwnerName = Owner ? Owner->GetName() : TEXT("Unknown");
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, 
				FString::Printf(TEXT("%s has died!"), *OwnerName));
		}
	}
}

float UHealthComponent::GetHealthPercentage() const
{
	return MaxHealth > 0.0f ? CurrentHealth / MaxHealth : 0.0f;
}

void UHealthComponent::TakeDamage(float DamageAmount, AActor* DamageSource)
{
	if (!CanTakeDamage() || DamageAmount <= 0.0f)
	{
		return;
	}
	
	float NewHealth = CurrentHealth - DamageAmount;
	SetCurrentHealth(NewHealth);
	
	if (GEngine)
	{
		AActor* Owner = GetOwner();
		FString OwnerName = Owner ? Owner->GetName() : TEXT("Unknown");
		FString SourceName = DamageSource ? DamageSource->GetName() : TEXT("Unknown");
		
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, 
			FString::Printf(TEXT("%s took %.1f damage from %s. Health: %.1f/%.1f"), 
				*OwnerName, DamageAmount, *SourceName, CurrentHealth, MaxHealth));
	}
}

void UHealthComponent::Heal(float HealAmount)
{
	if (HealAmount <= 0.0f || IsDead())
	{
		return;
	}
	
	float NewHealth = CurrentHealth + HealAmount;
	SetCurrentHealth(NewHealth);
	
	if (GEngine)
	{
		AActor* Owner = GetOwner();
		FString OwnerName = Owner ? Owner->GetName() : TEXT("Unknown");
		
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, 
			FString::Printf(TEXT("%s healed for %.1f. Health: %.1f/%.1f"), 
				*OwnerName, HealAmount, CurrentHealth, MaxHealth));
	}
}

