// GameDev.tv Podcast Squad 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterController.generated.h"

UCLASS()
class PROJECTMANHATTAN_API ACharacterController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterController();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* FollowCamera;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Override Jump class from ACharacter*/
	void Jump() override;

	/**  Override StopJumping class from ACharacter */
	void StopJumping() override;

	/**  Check if SpaceBar pressed or released */
	bool bIsSpaceBarDown;

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	 //void TurnAtRate(float Rate);

	 /**
	  * Called via input to turn look up/down at a given rate.
	  * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	  */
	  //void LookUpAtRate(float Rate);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};