// Warrior


#include "AnimNotifies/bCanHeavyComboNotifyState.h"
#include "Characters/WarriorBaseCharacter.h"

void UbCanHeavyComboNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	
	if (MeshComp && MeshComp->GetOwner())
	{
		if (AWarriorBaseCharacter* WarriorChar = Cast<AWarriorBaseCharacter>(MeshComp->GetOwner()))
		{
			WarriorChar->bCanHeavyCombo = true;
		}
	}
}

void UbCanHeavyComboNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	
	if (MeshComp && MeshComp->GetOwner())
	{
		if (AWarriorBaseCharacter* WarriorChar = Cast<AWarriorBaseCharacter>(MeshComp->GetOwner()))
		{
			WarriorChar->bCanHeavyCombo = false;
		}
	}
}
