#pragma once

#include "CoreMinimal.h"
#include "Species.generated.h"


UENUM(BlueprintType)
enum class ESpeciesType : uint8
{
    Human      UMETA(DisplayName = "Human"),
    Elf        UMETA(DisplayName = "Elf"),
    Orc        UMETA(DisplayName = "Orc"),
    Beast      UMETA(DisplayName = "Beast"),
    Animal     UMETA(DisplayName = "Animal"),
    Other      UMETA(DisplayName = "Other")
};

UENUM(BlueprintType)
enum class HumanSpeciesSubType : uint8
{
    HumanSapien   UMETA(DisplayName = "HumanSapien"),
    Giant         UMETA(DisplayName = "Giant"),
    Dwarf         UMETA(DisplayName = "Dwarf"),
    Valtheri      UMETA(DisplayName = "Valtheri"),
    Syvaris       UMETA(DisplayName = "Syvaris"),
	Adari 	      UMETA(DisplayName = "Adari"),
    None          UMETA(DisplayName = "None"),
};

UENUM(BlueprintType)
enum class HumanEthinicities : uint8
{
    AngoSaxon      UMETA(DisplayName = "AngoSaxon"),
    Nordic         UMETA(DisplayName = "Nordic"),
    Germanic       UMETA(DisplayName = "Germanic"),
    Celtic         UMETA(DisplayName = "Celtic"),
    Slavic         UMETA(DisplayName = "Slavic"),
    Latin          UMETA(DisplayName = "Latin"),
    Greek          UMETA(DisplayName = "Greek"),
    MiddleEastern  UMETA(DisplayName = "MiddleEastern"),
    Asian          UMETA(DisplayName = "Asian"),
    Mestizo        UMETA(DisplayName = "Mestizo"),
    African        UMETA(DisplayName = "African"),
    Mulatto        UMETA(DisplayName = "Mulatto"),
    Other          UMETA(DisplayName = "Other"),
    None           UMETA(DisplayName = "None"),
};

UENUM(BlueprintType)
enum class ElfSpeciesSubType : uint8
{
    High       UMETA(DisplayName = "High"),
    Wood       UMETA(DisplayName = "Wood"),
    Dark       UMETA(DisplayName = "Dark"),
    Snow       UMETA(DisplayName = "Snow"),
    Bloodwood  UMETA(DisplayName = "Bloodwood"),
    Drow       UMETA(DisplayName = "Drow"),
    Other      UMETA(DisplayName = "Other"),
    None       UMETA(DisplayName = "None"),
};

UENUM(BlueprintType)
enum class AnimalSpeciesSubType : uint8
{
    LandAnimal      UMETA(DisplayName = "LandAnimal"),
    AquaticAnimal   UMETA(DisplayName = "AquaticAnimal"),
    AerialAnimal    UMETA(DisplayName = "AerialAnimal"),
    Other           UMETA(DisplayName = "Other"),
    None            UMETA(DisplayName = "None"),
};

USTRUCT(BlueprintType)
struct FSpeciesInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Species")
    ESpeciesType SpeciesType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Species")
    HumanSpeciesSubType HumanSubType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Species")
    HumanEthinicities HumanEthinicity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Species")
    ElfSpeciesSubType ElfSubType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Species")
    AnimalSpeciesSubType AnimalSubType;

    FSpeciesInfo()
        : SpeciesType(ESpeciesType::Other), HumanSubType(HumanSpeciesSubType::None), HumanEthinicity(HumanEthinicities::None), ElfSubType(ElfSpeciesSubType::None), AnimalSubType(AnimalSpeciesSubType::None)
    {
    }
};