// Warrior


#include "AnimNotifies/bCanComboNotifyState.h"
#include "Characters/WarriorBaseCharacter.h"

void UbCanComboNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	
	if (MeshComp && MeshComp->GetOwner())
	{
		if (AWarriorBaseCharacter* WarriorChar = Cast<AWarriorBaseCharacter>(MeshComp->GetOwner()))
		{
			WarriorChar->bCanCombo = true;
		}
	}
}

void UbCanComboNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	
	if (MeshComp && MeshComp->GetOwner())
	{
		if (AWarriorBaseCharacter* WarriorChar = Cast<AWarriorBaseCharacter>(MeshComp->GetOwner()))
		{
			WarriorChar->bCanCombo = false;
		}
	}
	
}
