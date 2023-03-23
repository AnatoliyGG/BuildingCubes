#include "Character/BC_C_Character.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PawnMovementComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBC_Character, All, All);

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

	check(BC_CameraComponent);
	check(BS_FirstPersonMesh);
	
}

void ABC_C_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABC_C_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ABC_C_Character::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ABC_C_Character::MoveRight);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ABC_C_Character::AddControllerYawInput);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ABC_C_Character::AddControllerPitchInput);
	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ABC_C_Character::Jump);
	PlayerInputComponent->BindAction(FName("PrimaryAction"), IE_Pressed, this, &ABC_C_Character::StartAction);
	PlayerInputComponent->BindAction(FName("PrimaryAction"), IE_Released, this, &ABC_C_Character::EndAction);
}

void ABC_C_Character::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ABC_C_Character::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void ABC_C_Character::StartAction()
{
	UE_LOG(LogBC_Character, Display, TEXT("Start Actopn"));
}

void ABC_C_Character::EndAction()
{
	UE_LOG(LogBC_Character, Display, TEXT("End Actopn"));
}
