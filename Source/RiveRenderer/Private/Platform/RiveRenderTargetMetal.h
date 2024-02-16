// Copyright Rive, Inc. All rights reserved.

#pragma once

#if PLATFORM_APPLE

#include "RiveRenderTarget.h"

#if WITH_RIVE
THIRD_PARTY_INCLUDES_START
#include "rive/refcnt.hpp"
THIRD_PARTY_INCLUDES_END

namespace rive::pls
{
    class PLSRenderTargetMetal;
}

#endif // WITH_RIVE

namespace UE::Rive::Renderer::Private
{
    /**
     *
     */
    class FRiveRenderTargetMetal final : public FRiveRenderTarget
    {
        /**
         * Structor(s)
         */
        
    public:
        
        FRiveRenderTargetMetal(const TSharedRef<FRiveRenderer>& InRiveRenderer, const FName& InRiveName, UTextureRenderTarget2D* InRenderTarget);
        virtual ~FRiveRenderTargetMetal() override;
        //~ BEGIN : IRiveRenderTarget Interface
        
        virtual void CacheTextureTarget_RenderThread(FRHICommandListImmediate& RHICmdList, const FTexture2DRHIRef& InRHIResource) override;
        
#if WITH_RIVE
        
        virtual void DrawArtboard(uint8 Fit, float AlignX, float AlignY, rive::Artboard* InNativeArtboard, const FLinearColor DebugColor) override;
        
        //~ END : IRiveRenderTarget Interface
        
        //~ BEGIN : FRiveRenderTarget Interface
        
    protected:

        virtual rive::rcp<rive::pls::PLSRenderTarget> GetRenderTarget() const override;
        virtual void EndFrame() const override;
        
        //~ END : FRiveRenderTarget Interface
        
        /**
         * Attribute(s)
         */
        
    private:
        
        rive::rcp<rive::pls::PLSRenderTargetMetal> CachedPLSRenderTargetMetal;
        
#endif // WITH_RIVE
        
        mutable bool bIsCleared = false;
    };
}

#endif // PLATFORM_APPLE
