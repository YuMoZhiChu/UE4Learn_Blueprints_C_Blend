// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMarker.h"

// Sets default values
AQuestMarker::AQuestMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// CreateDefaultSubobject can only call in constructor
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	// Attach the component
	SetRootComponent(Root);
	// SetupAttachment also only call in constructor
	ParticleSystem->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AQuestMarker::BeginPlay()
{
	// hook up the delegate
	// &AQuestMarker::QuestUpdate function_pointer
	GetQuestManager()->CompletedQuest.AddDynamic(this, &AQuestMarker::QuestUpdate);
	RefreshVisibility();
}

void AQuestMarker::RefreshVisibility()
{
	FQuestInfo Quest = GetQuestManager()->GetQuest(QuestName);
	bool Visibility = GetQuestManager()->IsActiveQuest(QuestName) && Quest.Progress == ShowAtProgress;
	ParticleSystem->SetVisibility(Visibility);
}

void AQuestMarker::QuestUpdate(int32 Index)
{
	RefreshVisibility();
}
