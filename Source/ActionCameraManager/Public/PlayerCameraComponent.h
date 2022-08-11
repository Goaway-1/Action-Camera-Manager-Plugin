// Copyright 2022 Namman. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCameraComponent.generated.h"

// Add this component to your character and set "CameraManagerClass" to MainCameraManager
UCLASS(ClassGroup = (CameraManager), DisplayName = "PlayerCameraManager", meta = (BlueprintSpawnableComponent))
class ACTIONCAMERAMANAGER_API UPlayerCameraComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPlayerCameraComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	APlayerController* PlayerControllComp;
	class AMainCameraManager* CameraManager;	
};
