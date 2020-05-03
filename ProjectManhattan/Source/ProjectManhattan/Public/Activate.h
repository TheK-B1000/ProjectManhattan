// GameDev.tv Podcast Squad 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Activate.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTMANHATTAN_API UActivate : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActivate();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
