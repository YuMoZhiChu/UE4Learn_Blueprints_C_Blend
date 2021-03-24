// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
/*generated 一定要放在最后*/
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class BLUEPRINTSTOCPP_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	UFUNCTION(BlueprintCallable)
	void GrabPress();

	UFUNCTION(BlueprintCallable)
	void GrabRelease();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetMaxGrabLocation() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetHoldLocation() const;

	// Ref in BP, Pointer in C++
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UPhysicsHandleComponent* GetPhysicsComponent() const;

	// To Implement in BP, it is a virtual function, define here, no need to add virtual key word
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void NotifyQuestActor(AActor* Actor);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxGrabDistance = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HoldDistance = 100.0f;

	// AActor*& for output actor, [&] for output
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool TraceForPhysicsBodies(AActor*& HitActor, UPrimitiveComponent*& HitComponent);
};
