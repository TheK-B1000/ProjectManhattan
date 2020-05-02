// GameDev.tv Community Podcast

#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get Player Viewpoint
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	FHitResult HitResult;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint
	(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewPointLocation + (PlayerViewPointRotation.Vector() + Reach);

	// For debugging 
	DrawDebugLine
	(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(0, 255, 0),
		false,
		0.f,
		0,
		5.f
	);

	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	// See what the debug line hits
	GetWorld()->LineTraceSingleByObjectType
	(
		HitResult,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);
	
	// Log what was hit
	AActor* ActorHit = HitResult.GetActor();

		if (ActorHit)
		{
			UE_LOG(LogTemp, Warning, TEXT("Ray-cast hit: %s"), *(ActorHit->GetName()));
		}
	


}

void UGrabber::GetPlayerViewpoint()
{

}

