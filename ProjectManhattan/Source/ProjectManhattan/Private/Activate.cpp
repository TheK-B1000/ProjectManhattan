// GameDev.tv Podcast Squad 2020


#include "Activate.h"

// Sets default values for this component's properties
UActivate::UActivate()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActivate::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActivate::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

