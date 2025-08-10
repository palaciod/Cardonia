// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageableInterface.generated.h"

// Forward declarations
class AActor;
class UPrimitiveComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UDamageableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface for objects that can take damage and have health
 */
class CARDONIA_API IDamageableInterface
{
	GENERATED_BODY()

public:
	// Core health functions - Blueprint Implementable (designers control values)
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Health")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Health")
	float GetCurrentHealth() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Health")
	void SetCurrentHealth(float NewHealth);

	// Complex logic functions - C++ with defaults (developers control logic)
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Health")
	float GetHealthPercentage() const;
	virtual float GetHealthPercentage_Implementation() const 
	{ 
		float MaxHP = GetMaxHealth();
		return MaxHP > 0.0f ? GetCurrentHealth() / MaxHP : 0.0f;
	}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Health")
	void TakeDamage(float DamageAmount, AActor* DamageSource);
	virtual void TakeDamage_Implementation(float DamageAmount, AActor* DamageSource) {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Health")
	void Heal(float HealAmount);
	virtual void Heal_Implementation(float HealAmount) {}

	// State queries - C++ with defaults (safe logic)
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Health")
	bool IsAlive() const;
	virtual bool IsAlive_Implementation() const { return GetCurrentHealth() > 0.0f; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Health")
	bool IsDead() const;
	virtual bool IsDead_Implementation() const { return GetCurrentHealth() <= 0.0f; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Health")
	bool IsAtFullHealth() const;
	virtual bool IsAtFullHealth_Implementation() const { return GetCurrentHealth() >= GetMaxHealth(); }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Health")
	bool CanTakeDamage() const;
	virtual bool CanTakeDamage_Implementation() const { return IsAlive(); }

	// Events - Blueprint Implementable (designers control behavior)
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Health")
	void OnDeath();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Health")
	void OnHealthChanged(float OldHealth, float NewHealth);
};
