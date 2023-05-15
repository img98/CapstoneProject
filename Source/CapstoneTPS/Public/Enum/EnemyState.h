#pragma once

UENUM(BlueprintType)
enum class EEnemyState :uint8
{
	EES_Patrol UMETA(DisplayName = "Patrol"),
	EES_InCombat UMETA(DisplayName = "InCombat"),
	EES_Dead UMETA(DisplayName = "Dead"),

	EES_MAX UMETA(DisplayName = "DefaultMAX")
};