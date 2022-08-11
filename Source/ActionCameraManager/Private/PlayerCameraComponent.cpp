// Copyright 2022 Namman. All Rights Reserved.

#include "PlayerCameraComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "MainCameraManager.h"

UPlayerCameraComponent::UPlayerCameraComponent(){
	PrimaryComponentTick.bCanEverTick = true;

}
void UPlayerCameraComponent::BeginPlay(){
	Super::BeginPlay();

	/** Find MainCameraManager & Set */
	AMainCameraManager* TargetCamera = Cast<AMainCameraManager>(UGameplayStatics::GetActorOfClass(this, AMainCameraManager::StaticClass()));

	if (TargetCamera) {
		CameraManager = TargetCamera;
		ACharacter* Player = Cast<ACharacter>(GetOwner());
		PlayerControllComp = Cast<APlayerController>(Player->GetController());

		/** Move the Player Controller to MainCameraManager */
		if (PlayerControllComp) {
			PlayerControllComp->bAutoManageActiveCameraTarget = false;
			PlayerControllComp->ClientSetViewTarget(CameraManager);
		}
	}

	if (CameraManager) CameraManager->SetPlayer(GetOwner());
}
void UPlayerCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/** Setting the rotation of the controller according to the rotation of the CameraManager */
	if (CameraManager && PlayerControllComp && GetOwner()->HasAuthority()) {
		FRotator NRot = FRotator(CameraManager->GetActorRotation().Pitch, CameraManager->GetActorRotation().Yaw, PlayerControllComp->GetControlRotation().Roll);
		PlayerControllComp->ClientSetRotation(NRot);
	}
}
