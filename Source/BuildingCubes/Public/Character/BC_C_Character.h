#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "BC_C_Character.generated.h"

UCLASS()
class BUILDINGCUBES_API ABC_C_Character : public ACharacter
{
	GENERATED_BODY()

public:
	ABC_C_Character();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UCameraComponent* BC_CameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* BC_FirstPersonMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* BC_FirstPersonGun;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* BC_LightShpere;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartAction();
	void EndAction();
};