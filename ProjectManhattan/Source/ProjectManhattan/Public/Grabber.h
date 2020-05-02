// GameDev.tv Community Podcast

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTMANHATTAN_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SetupPhysicsHandleComponent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetupInputComponent();

	void Grab();

	void Release();

	FHitResult GetFirstPhysicsBodyInReach();

	AActor* Player;

	UInputComponent* InputComponent = nullptr;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

private:
	float Reach = 50.f;

};
