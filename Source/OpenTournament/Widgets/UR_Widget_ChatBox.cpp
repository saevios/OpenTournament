// Copyright (c) Open Tournament Project, All Rights Reserved.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "UR_Widget_ChatBox.h"

#include <EnhancedInputComponent.h>
#include <Components/InputComponent.h>

#include "Components/VerticalBox.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

void UUR_Widget_ChatBox::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (const APlayerController* PC = Cast<APlayerController>(GetOwningPlayer()); IsValid(PC))
    {
        if (auto Input = PC->InputComponent)
        {
            //@! TODO EnhancedInput
            if (auto EnhancedInput = Cast<UEnhancedInputComponent>(Input))
            {
                // UInputAction
                //EnhancedInput->BindAction()
            }
            else
            {
                InputComponent->BindAction("BeginSay", IE_Pressed, this, &UUR_Widget_ChatBox::OnBeginSay);
                InputComponent->BindAction("BeginTeamSay", IE_Pressed, this, &UUR_Widget_ChatBox::OnBeginTeamSay);
            }
        }
    }
}
