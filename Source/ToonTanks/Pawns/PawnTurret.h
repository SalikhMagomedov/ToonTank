// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.f;
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRange = 200.f;

	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn;

	void CheckFireCondition();

	float ReturnDistanceToPlayer();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void HandleDestruction() override;
};
