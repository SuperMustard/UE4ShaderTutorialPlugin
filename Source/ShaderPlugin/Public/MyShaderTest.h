#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Classes/Kismet/BlueprintFunctionLibrary.h"

#include "MyShaderTest.generated.h"

USTRUCT(BlueprintType)
struct FMyUniformData
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)
		FLinearColor testColor;

		UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)
		UTexture* UnifromTexture;
};

UCLASS(MinimalAPI, meta = (ScriptName = "TestShaderLibary"))
class UTestShaderBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "ShaderPlugin", meta = (WorldContext = "WorldContextObject"))
	static void DrawTestShaderRenderTarget(class UTextureRenderTarget2D* OutputRenderTarget, AActor* Ac, FLinearColor MyColor, UTexture* MyTexture, FMyUniformData uniformData);
};