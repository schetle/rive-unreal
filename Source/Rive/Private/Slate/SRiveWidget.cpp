// Copyright Rive, Inc. All rights reserved.

#include "Slate/SRiveWidget.h"
#include "RiveWidgetView.h"

void SRiveWidget::Construct(const FArguments& InArgs, TSoftObjectPtr<URiveFile> InRiveFile)
{
    ChildSlot
        [
            SNew(SVerticalBox)

                + SVerticalBox::Slot()
                [
                    SAssignNew(RiveWidgetView, SRiveWidgetView, InRiveFile)
                ]
        ];
}

void SRiveWidget::SetRiveFile(URiveFile* InRiveFile)
{
    RiveFile = InRiveFile;
}
