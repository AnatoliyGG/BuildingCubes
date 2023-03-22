#include "Character/BC_C_Character.h"

ABC_C_Character::ABC_C_Character()
{
	PrimaryActorTick.bCanEverTick = true;

	BC_CameraComponent = CreateDefaultSubobject<UCameraComponent>("BC_CameraComponent");
	BC_CameraComponent->SetupAttachment(GetRootComponent());

	BS_FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>("BS_FirstPersonMesh");
	BS_FirstPersonMesh->SetupAttachment(BC_CameraComponent);

}

void ABC_C_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABC_C_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABC_C_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

