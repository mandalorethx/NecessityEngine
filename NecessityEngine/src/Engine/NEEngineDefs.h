#pragma once

enum NEShaderStages
{
    NE_Shader_Stage_Vertex,
    NE_Shader_Stage_Tess_Control,
    NE_Shader_Stage_Tess_Eval,
    NE_Shader_Stage_Geometry,
    NE_Shader_Stage_Fragment,
    NE_Shader_Stage_Compute,
    NE_Shader_Stage_Count,
};

enum NEShaderStageFlags
{
    NE_Shader_Stage_Flag_Vertex = 1 << NE_Shader_Stage_Vertex,
    NE_Shader_Stage_Flag_Tess_Control = 1 << NE_Shader_Stage_Tess_Control,
    NE_Shader_Stage_Flag_Tess_Eval = 1 << NE_Shader_Stage_Tess_Eval,
    NE_Shader_Stage_Flag_Geometry = 1 << NE_Shader_Stage_Geometry,
    NE_Shader_Stage_Flag_Fragment = 1 << NE_Shader_Stage_Fragment,
    NE_Shader_Stage_Flag_Compute = 1 << NE_Shader_Stage_Compute,
};

enum NEFormat
{
    NE_Format_UNDEFINED,
    NE_Format_R8_UNORM,
    NE_Format_R8_SRGB,
    NE_Format_R8G8B8A8_UNORM,
    NE_Format_R8G8B8A8_SRGB,
    NE_Format_R16_UINT,
    NE_Format_R16_SINT,
    NE_Format_R16_SFLOAT,
    NE_Format_R16G16_UINT,
    NE_Format_R16G16_SINT,
    NE_Format_R16G16_SFLOAT,
    NE_Format_R16G16B16_UINT,
    NE_Format_R16G16B16_SINT,
    NE_Format_R16G16B16_SFLOAT,
    NE_Format_R16G16B16A16_UINT,
    NE_Format_R16G16B16A16_SINT,
    NE_Format_R16G16B16A16_SFLOAT,
    NE_Format_R32_UINT,
    NE_Format_R32_SINT,
    NE_Format_R32_SFLOAT,
    NE_Format_R32G32_UINT,
    NE_Format_R32G32_SINT,
    NE_Format_R32G32_SFLOAT,
    NE_Format_R32G32B32_UINT,
    NE_Format_R32G32B32_SINT,
    NE_Format_R32G32B32_SFLOAT,
    NE_Format_R32G32B32A32_UINT,
    NE_Format_R32G32B32A32_SINT,
    NE_Format_R32G32B32A32_SFLOAT,
    NE_Format_D16_UNORM,
    NE_Format_D16_UNORM_S8_UINT,
    NE_Format_D24_UNORM_S8_UINT,
    NE_Format_D32_SFLOAT_S8_UINT,
};

