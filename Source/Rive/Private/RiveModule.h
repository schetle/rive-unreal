// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IRiveModule.h"

namespace UE::Rive::Private
{
    class FRiveModule final : public IRiveModule
    {
        //~ BEGIN : IModuleInterface Interface

    public:

        virtual void StartupModule() override;

        virtual void ShutdownModule() override;

        //~ END : IModuleInterface Interface

        /**
         * Implementation(s)
         */

    private:

        void TestRiveIntegration();
    };
}
