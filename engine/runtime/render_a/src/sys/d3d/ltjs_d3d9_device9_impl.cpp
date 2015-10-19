#include "precompile.h"
#include "ltjs_d3d9_device9_impl.h"
#include "ltjs_d3d9_exception.h"
#include "ltjs_d3d9_id3d9_impl.h"
#include "ltjs_d3d9_wrapper.h"


namespace ltjs {
namespace d3d9 {


const GLchar* const Device9Impl::ogl_vertex_shader_source =
R"LTJS_RAW_STRING(

#version 330 core

void main()
{
    gl_Position = vec4(0.0);
}

)LTJS_RAW_STRING";


const GLchar* const Device9Impl::ogl_fragment_shader_source =
R"LTJS_RAW_STRING(

#version 330 core

out vec4 result;

void main()
{
    result = vec4(0.0);
}

)LTJS_RAW_STRING";


// ========
// IUnknown

IFACEMETHODIMP Device9Impl::QueryInterface(
    REFIID riid,
    void** ppvObj)
{
    return query_interface(
        IID_IDirect3DDevice9,
        riid,
        ppvObj);
}

IFACEMETHODIMP_(ULONG) Device9Impl::AddRef()
{
    return add_ref();
}

IFACEMETHODIMP_(ULONG) Device9Impl::Release()
{
    return release(
        this);
}

// IUnknown
// ========


// ================
// IDirect3DDevice9

IFACEMETHODIMP Device9Impl::TestCooperativeLevel()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(UINT) Device9Impl::GetAvailableTextureMem()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::EvictManagedResources()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetDirect3D(
    IDirect3D9** ppD3D9)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetDeviceCaps(
    D3DCAPS9* pCaps)
{
    if (!pCaps) {
        return D3DERR_INVALIDCALL;
    }

    *pCaps = d3d9_caps;

    return D3D_OK;
}

IFACEMETHODIMP Device9Impl::GetDisplayMode(
    UINT iSwapChain,
    D3DDISPLAYMODE* pMode)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetCreationParameters(
    D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetCursorProperties(
    UINT XHotSpot,
    UINT YHotSpot,
    IDirect3DSurface9* pCursorBitmap)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(void) Device9Impl::SetCursorPosition(
    int X,
    int Y,
    DWORD Flags)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(BOOL) Device9Impl::ShowCursor(
    BOOL bShow)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateAdditionalSwapChain(
    D3DPRESENT_PARAMETERS* pPresentationParameters,
    IDirect3DSwapChain9** pSwapChain)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetSwapChain(
    UINT iSwapChain,
    IDirect3DSwapChain9** pSwapChain)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(UINT) Device9Impl::GetNumberOfSwapChains()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::Reset(
    D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::Present(
    const RECT* pSourceRect,
    const RECT* pDestRect,
    HWND hDestWindowOverride,
    const RGNDATA* pDirtyRegion)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetBackBuffer(
    UINT iSwapChain,
    UINT iBackBuffer,
    D3DBACKBUFFER_TYPE Type,
    IDirect3DSurface9** ppBackBuffer)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetRasterStatus(
    UINT iSwapChain,
    D3DRASTER_STATUS* pRasterStatus)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetDialogBoxMode(
    BOOL bEnableDialogs)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(void) Device9Impl::SetGammaRamp(
    UINT iSwapChain,
    DWORD Flags,
    const D3DGAMMARAMP* pRamp)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(void) Device9Impl::GetGammaRamp(
    UINT iSwapChain,
    D3DGAMMARAMP* pRamp)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateTexture(
    UINT Width,
    UINT Height,
    UINT Levels,
    DWORD Usage,
    D3DFORMAT Format,
    D3DPOOL Pool,
    IDirect3DTexture9** ppTexture,
    HANDLE* pSharedHandle)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateVolumeTexture(
    UINT Width,
    UINT Height,
    UINT Depth,
    UINT Levels,
    DWORD Usage,
    D3DFORMAT Format,
    D3DPOOL Pool,
    IDirect3DVolumeTexture9** ppVolumeTexture,
    HANDLE* pSharedHandle)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateCubeTexture(
    UINT EdgeLength,
    UINT Levels,
    DWORD Usage,
    D3DFORMAT Format,
    D3DPOOL Pool,
    IDirect3DCubeTexture9** ppCubeTexture,
    HANDLE* pSharedHandle)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateVertexBuffer(
    UINT Length,
    DWORD Usage,
    DWORD FVF,
    D3DPOOL Pool,
    IDirect3DVertexBuffer9** ppVertexBuffer,
    HANDLE* pSharedHandle)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateIndexBuffer(
    UINT Length,
    DWORD Usage,
    D3DFORMAT Format,
    D3DPOOL Pool,
    IDirect3DIndexBuffer9** ppIndexBuffer,
    HANDLE* pSharedHandle)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateRenderTarget(
    UINT Width,
    UINT Height,
    D3DFORMAT Format,
    D3DMULTISAMPLE_TYPE MultiSample,
    DWORD MultisampleQuality,
    BOOL Lockable,
    IDirect3DSurface9** ppSurface,
    HANDLE* pSharedHandle)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateDepthStencilSurface(
    UINT Width,
    UINT Height,
    D3DFORMAT Format,
    D3DMULTISAMPLE_TYPE MultiSample,
    DWORD MultisampleQuality,
    BOOL Discard,
    IDirect3DSurface9** ppSurface,
    HANDLE* pSharedHandle)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::UpdateSurface(
    IDirect3DSurface9* pSourceSurface,
    const RECT* pSourceRect,
    IDirect3DSurface9* pDestinationSurface,
    const POINT* pDestPoint)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::UpdateTexture(
    IDirect3DBaseTexture9* pSourceTexture,
    IDirect3DBaseTexture9* pDestinationTexture)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetRenderTargetData(
    IDirect3DSurface9* pRenderTarget,
    IDirect3DSurface9* pDestSurface)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetFrontBufferData(
    UINT iSwapChain,
    IDirect3DSurface9* pDestSurface)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::StretchRect(
    IDirect3DSurface9* pSourceSurface,
    const RECT* pSourceRect,
    IDirect3DSurface9* pDestSurface,
    const RECT* pDestRect,
    D3DTEXTUREFILTERTYPE Filter)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::ColorFill(
    IDirect3DSurface9* pSurface,
    const RECT* pRect,
    D3DCOLOR color)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateOffscreenPlainSurface(
    UINT Width,
    UINT Height,
    D3DFORMAT Format,
    D3DPOOL Pool,
    IDirect3DSurface9** ppSurface,
    HANDLE* pSharedHandle)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetRenderTarget(
    DWORD RenderTargetIndex,
    IDirect3DSurface9* pRenderTarget)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetRenderTarget(
    DWORD RenderTargetIndex,
    IDirect3DSurface9** ppRenderTarget)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetDepthStencilSurface(
    IDirect3DSurface9* pNewZStencil)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetDepthStencilSurface(
    IDirect3DSurface9** ppZStencilSurface)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::BeginScene()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::EndScene()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::Clear(
    DWORD Count,
    const D3DRECT* pRects,
    DWORD Flags,
    D3DCOLOR Color,
    float Z,
    DWORD Stencil)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetTransform(
    D3DTRANSFORMSTATETYPE State,
    const D3DMATRIX* pMatrix)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetTransform(
    D3DTRANSFORMSTATETYPE State,
    D3DMATRIX* pMatrix)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::MultiplyTransform(
    D3DTRANSFORMSTATETYPE State,
    const D3DMATRIX* pMatrix)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetViewport(
    const D3DVIEWPORT9* pViewport)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetViewport(
    D3DVIEWPORT9* pViewport)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetMaterial(
    const D3DMATERIAL9* pMaterial)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetMaterial(
    D3DMATERIAL9* pMaterial)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetLight(
    DWORD Index,
    const D3DLIGHT9* pLight)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetLight(
    DWORD Index,
    D3DLIGHT9* pLight)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::LightEnable(
    DWORD Index,
    BOOL Enable)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetLightEnable(
    DWORD Index,
    BOOL* pEnable)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetClipPlane(
    DWORD Index,
    const float* pPlane)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetClipPlane(
    DWORD Index,
    float* pPlane)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetRenderState(
    D3DRENDERSTATETYPE State,
    DWORD Value)
{
    validate_render_state_value(
        State,
        Value);

    if (render_state[State] != Value) {
        render_state[State] = Value;
        render_state_changes.set(State);
    }

    return D3D_OK;
}

IFACEMETHODIMP Device9Impl::GetRenderState(
    D3DRENDERSTATETYPE State,
    DWORD* pValue)
{
    switch(State) {
    case D3DRS_ZENABLE:
    case D3DRS_FILLMODE:
    case D3DRS_SHADEMODE:
    case D3DRS_ZWRITEENABLE:
    case D3DRS_ALPHATESTENABLE:
    case D3DRS_SRCBLEND:
    case D3DRS_DESTBLEND:
    case D3DRS_CULLMODE:
    case D3DRS_ZFUNC:
    case D3DRS_ALPHAREF:
    case D3DRS_ALPHAFUNC:
    case D3DRS_DITHERENABLE:
    case D3DRS_ALPHABLENDENABLE:
    case D3DRS_FOGENABLE:
    case D3DRS_SPECULARENABLE:
    case D3DRS_FOGCOLOR:
    case D3DRS_FOGTABLEMODE:
    case D3DRS_FOGSTART:
    case D3DRS_FOGEND:
    case D3DRS_TEXTUREFACTOR:
    case D3DRS_CLIPPING:
    case D3DRS_LIGHTING:
    case D3DRS_AMBIENT:
    case D3DRS_FOGVERTEXMODE:
    case D3DRS_COLORVERTEX:
    case D3DRS_NORMALIZENORMALS:
    case D3DRS_DIFFUSEMATERIALSOURCE:
    case D3DRS_SPECULARMATERIALSOURCE:
    case D3DRS_AMBIENTMATERIALSOURCE:
    case D3DRS_EMISSIVEMATERIALSOURCE:
    case D3DRS_VERTEXBLEND:
    case D3DRS_INDEXEDVERTEXBLENDENABLE:
    case D3DRS_SLOPESCALEDEPTHBIAS:
    case D3DRS_DEPTHBIAS:
        break;

    default:
        throw Exception("Unsupported render state type.");
    }

    if (!pValue) {
        return D3DERR_INVALIDCALL;
    }

    *pValue = render_state[State];
    return D3D_OK;
}

IFACEMETHODIMP Device9Impl::CreateStateBlock(
    D3DSTATEBLOCKTYPE Type,
    IDirect3DStateBlock9** ppSB)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::BeginStateBlock()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::EndStateBlock(
    IDirect3DStateBlock9** ppSB)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetClipStatus(
    const D3DCLIPSTATUS9* pClipStatus)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetClipStatus(
    D3DCLIPSTATUS9* pClipStatus)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetTexture(
    DWORD Stage,
    IDirect3DBaseTexture9** ppTexture)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetTexture(
    DWORD Stage,
    IDirect3DBaseTexture9* pTexture)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetTextureStageState(
    DWORD Stage,
    D3DTEXTURESTAGESTATETYPE Type,
    DWORD* pValue)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetTextureStageState(
    DWORD Stage,
    D3DTEXTURESTAGESTATETYPE Type,
    DWORD Value)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetSamplerState(
    DWORD Sampler,
    D3DSAMPLERSTATETYPE Type,
    DWORD* pValue)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetSamplerState(
    DWORD Sampler,
    D3DSAMPLERSTATETYPE Type,
    DWORD Value)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::ValidateDevice(
    DWORD* pNumPasses)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetPaletteEntries(
    UINT PaletteNumber,
    const PALETTEENTRY* pEntries)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetPaletteEntries(
    UINT PaletteNumber,
    PALETTEENTRY* pEntries)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetCurrentTexturePalette(
    UINT PaletteNumber)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetCurrentTexturePalette(
    UINT *PaletteNumber)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetScissorRect(
    const RECT* pRect)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetScissorRect(
    RECT* pRect)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetSoftwareVertexProcessing(
    BOOL bSoftware)
{
    switch (bSoftware) {
    case FALSE:
    case TRUE:
        d3d9_software_vertex_processing = bSoftware;
        return D3D_OK;

    default:
        return D3DERR_INVALIDCALL;
    }
}

IFACEMETHODIMP_(BOOL) Device9Impl::GetSoftwareVertexProcessing()
{
    return d3d9_software_vertex_processing;
}

IFACEMETHODIMP Device9Impl::SetNPatchMode(
    float nSegments)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(float) Device9Impl::GetNPatchMode()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::DrawPrimitive(
    D3DPRIMITIVETYPE PrimitiveType,
    UINT StartVertex,
    UINT PrimitiveCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::DrawIndexedPrimitive(
    D3DPRIMITIVETYPE,
    INT BaseVertexIndex,
    UINT MinVertexIndex,
    UINT NumVertices,
    UINT startIndex,
    UINT primCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::DrawPrimitiveUP(
    D3DPRIMITIVETYPE PrimitiveType,
    UINT PrimitiveCount,
    const void* pVertexStreamZeroData,
    UINT VertexStreamZeroStride)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::DrawIndexedPrimitiveUP(
    D3DPRIMITIVETYPE PrimitiveType,
    UINT MinVertexIndex,
    UINT NumVertices,
    UINT PrimitiveCount,
    const void* pIndexData,
    D3DFORMAT IndexDataFormat,
    const void* pVertexStreamZeroData,
    UINT VertexStreamZeroStride)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::ProcessVertices(
    UINT SrcStartIndex,
    UINT DestIndex,
    UINT VertexCount,
    IDirect3DVertexBuffer9* pDestBuffer,
    IDirect3DVertexDeclaration9* pVertexDecl,
    DWORD Flags)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateVertexDeclaration(
    const D3DVERTEXELEMENT9* pVertexElements,
    IDirect3DVertexDeclaration9** ppDecl)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetVertexDeclaration(
    IDirect3DVertexDeclaration9* pDecl)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetVertexDeclaration(
    IDirect3DVertexDeclaration9** ppDecl)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetFVF(
    DWORD FVF)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetFVF(
    DWORD* pFVF)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateVertexShader(
    const DWORD* pFunction,
    IDirect3DVertexShader9** ppShader)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetVertexShader(
    IDirect3DVertexShader9* pShader)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetVertexShader(
    IDirect3DVertexShader9** ppShader)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetVertexShaderConstantF(
    UINT StartRegister,
    const float* pConstantData,
    UINT Vector4fCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetVertexShaderConstantF(
    UINT StartRegister,
    float* pConstantData,
    UINT Vector4fCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetVertexShaderConstantI(
    UINT StartRegister,
    const int* pConstantData,
    UINT Vector4iCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetVertexShaderConstantI(
    UINT StartRegister,
    int* pConstantData,
    UINT Vector4iCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetVertexShaderConstantB(
    UINT StartRegister,
    const BOOL* pConstantData,
    UINT  BoolCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetVertexShaderConstantB(
    UINT StartRegister,
    BOOL* pConstantData,
    UINT BoolCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetStreamSource(
    UINT StreamNumber,
    IDirect3DVertexBuffer9* pStreamData,
    UINT OffsetInBytes,
    UINT Stride)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetStreamSource(
    UINT StreamNumber,
    IDirect3DVertexBuffer9** ppStreamData,
    UINT* pOffsetInBytes,
    UINT* pStride)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetStreamSourceFreq(
    UINT StreamNumber,
    UINT Setting)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetStreamSourceFreq(
    UINT StreamNumber,
    UINT* pSetting)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetIndices(
    IDirect3DIndexBuffer9* pIndexData)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetIndices(
    IDirect3DIndexBuffer9** ppIndexData)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreatePixelShader(
    const DWORD* pFunction,
    IDirect3DPixelShader9** ppShader)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetPixelShader(
    IDirect3DPixelShader9* pShader)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetPixelShader(
    IDirect3DPixelShader9** ppShader)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetPixelShaderConstantF(
    UINT StartRegister,
    const float* pConstantData,
    UINT Vector4fCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetPixelShaderConstantF(
    UINT StartRegister,
    float* pConstantData,
    UINT Vector4fCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetPixelShaderConstantI(
    UINT StartRegister,
    const int* pConstantData,
    UINT Vector4iCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetPixelShaderConstantI(
    UINT StartRegister,
    int* pConstantData,
    UINT Vector4iCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::SetPixelShaderConstantB(
    UINT StartRegister,
    const BOOL* pConstantData,
    UINT  BoolCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetPixelShaderConstantB(
    UINT StartRegister,
    BOOL* pConstantData,
    UINT BoolCount)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::DrawRectPatch(
    UINT Handle,
    const float* pNumSegs,
    const D3DRECTPATCH_INFO* pRectPatchInfo)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::DrawTriPatch(
    UINT Handle,
    const float* pNumSegs,
    const D3DTRIPATCH_INFO* pTriPatchInfo)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::DeletePatch(
    UINT Handle)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::CreateQuery(
    D3DQUERYTYPE Type,
    IDirect3DQuery9** ppQuery)
{
    throw Exception("Not implemented.");
}

// IDirect3DDevice9
// ================


// =========
// Internals

Device9Impl::Device9Impl(
    ID3d9Impl* id3d9_impl) :
        d3d9(id3d9_impl),
        d3d9_caps(),
        d3d9_software_vertex_processing(FALSE),
        render_state(),
        render_state_changes(),
        view_matrix(),
        view_matrix_changed(),
        projection_matrix(),
        projection_matrix_changed(),
        world_matrices{},
        world_matrices_changes(),
        ogl_error_message(),
        ogl_vertex_shader_object(),
        ogl_vertex_shader_warning_message(),
        ogl_fragment_shader_object(),
        ogl_fragment_shader_warning_message(),
        ogl_program_object(),
        ogl_program_warning_message()
{
}

Device9Impl::~Device9Impl()
{
    uninitialize();
}

HRESULT Device9Impl::d3d9_get_adapter_identifier(
    DWORD flags,
    D3DADAPTER_IDENTIFIER9 *id_ptr)
{
    if (flags != 0) {
        return D3DERR_INVALIDCALL;
    }

    if (!id_ptr) {
        return D3DERR_INVALIDCALL;
    }


    static bool is_initialized;
    static D3DADAPTER_IDENTIFIER9 id;

    if (!is_initialized) {
        const auto driver_name = "";
        const auto description = "Primary Display Driver";
        const auto device_name = "\\\\.\\DISPLAY1";

        std::string::traits_type::copy(
            id.Driver,
            driver_name,
            std::string::traits_type::length(
                driver_name)
        );

        std::string::traits_type::copy(
            id.Description,
            description,
            std::string::traits_type::length(
                description)
        );

        std::string::traits_type::copy(
            id.DeviceName,
            device_name,
            std::string::traits_type::length(
                device_name)
        );

        is_initialized = true;
    }

    *id_ptr = id;

    return D3D_OK;
}

HRESULT Device9Impl::d3d9_get_adapter_display_mode(
    D3DDISPLAYMODE *mode_ptr)
{
    if (!mode_ptr) {
        return D3DERR_INVALIDCALL;
    }


    D3DDISPLAYMODE ddm;
    ZeroMemory(&ddm, sizeof(ddm));

    DEVMODEA dm;
    ZeroMemory(&dm, sizeof(dm));
    dm.dmSize = sizeof(dm);

    auto enum_display_settings_result = ::EnumDisplaySettingsA(
        nullptr,
        ENUM_CURRENT_SETTINGS,
        &dm
    );

    if (enum_display_settings_result != FALSE &&
        dm.dmBitsPerPel == 32)
    {
        ddm.Width = dm.dmPelsWidth;
        ddm.Height = dm.dmPelsHeight;
        ddm.RefreshRate = dm.dmDisplayFrequency;
        ddm.Format = D3DFMT_X8R8G8B8;
    }

    *mode_ptr = ddm;

    return D3D_OK;
}

UINT Device9Impl::d3d9_get_adapter_mode_count(
    D3DFORMAT format)
{
    if (format != D3DFMT_X8R8G8B8) {
        return 0;
    }


    UINT mode_count = 0;

    for (DWORD i = 0; ; ++i) {
        DEVMODEA dm;
        ZeroMemory(&dm, sizeof(dm));
        dm.dmSize = sizeof(dm);

        auto enum_display_settings_result = ::EnumDisplaySettingsA(
            nullptr,
            i,
            &dm
        );

        if (enum_display_settings_result == FALSE) {
            break;
        }

        if (dm.dmBitsPerPel != 32) {
            continue;
        }

        mode_count += 1;
    }

    return mode_count;
}

HRESULT Device9Impl::d3d9_enum_adapter_modes(
    D3DFORMAT format,
    UINT mode,
    D3DDISPLAYMODE* mode_ptr)
{
    if (format != D3DFMT_X8R8G8B8) {
        return D3DERR_NOTAVAILABLE;
    }

    if (!mode_ptr) {
        return D3DERR_INVALIDCALL;
    }

    ZeroMemory(mode_ptr, sizeof(*mode_ptr));

    DWORD mode_index = 0;

    for (DWORD i = 0; ; ++i) {
        DEVMODEA dm;
        ZeroMemory(&dm, sizeof(dm));
        dm.dmSize = sizeof(dm);

        auto enum_display_settings_result = ::EnumDisplaySettingsA(
            nullptr,
            i,
            &dm
        );

        if (enum_display_settings_result == FALSE) {
            return D3DERR_NOTAVAILABLE;
        }

        if (dm.dmBitsPerPel != 32) {
            continue;
        }

        if (mode_index == mode) {
            D3DDISPLAYMODE ddm;
            ZeroMemory(&ddm, sizeof(ddm));

            ddm.Width = dm.dmPelsWidth;
            ddm.Height = dm.dmPelsHeight;
            ddm.RefreshRate = dm.dmDisplayFrequency;
            ddm.Format = D3DFMT_X8R8G8B8;

            *mode_ptr = ddm;

            return D3D_OK;
        }

        mode_index += 1;
    }
}

HRESULT Device9Impl::d3d9_get_device_caps(
    D3DDEVTYPE device_type,
    D3DCAPS9* caps_ptr)
{
    if (device_type != D3DDEVTYPE_HAL) {
        return D3DERR_INVALIDCALL;
    }

    if (!caps_ptr) {
        return D3DERR_INVALIDCALL;
    }


    D3DCAPS9 caps;
    ZeroMemory(&caps, sizeof(caps));

    auto is_succeed = true;

    auto instance_handle =
        ::GetModuleHandleW(nullptr);


    // Register window class
    //

    ATOM window_class_id = 0;

    if (is_succeed) {
        WNDCLASSEXW wce;
        ZeroMemory(&wce, sizeof(wce));
        wce.cbSize = sizeof(wce);
        wce.style = CS_OWNDC;
        wce.lpfnWndProc = ::DefWindowProcW;
        wce.hInstance = instance_handle;
        wce.hbrBackground = static_cast<HBRUSH>(::GetStockObject(BLACK_BRUSH));
        wce.lpszClassName = L"LTJS Dummy Window Class";

        window_class_id = ::RegisterClassExW(
            &wce);

        if (window_class_id == 0) {
            is_succeed = false;
        }
    }


    // Create a window
    //

    HWND window_handle = nullptr;

    if (is_succeed) {
        window_handle = ::CreateWindowExW(
            0, // extended style
            reinterpret_cast<LPCWSTR>(
                static_cast<size_t>(window_class_id)), // class name/atom
            L"Dummy Window", // title
            WS_BORDER, // the style of the window
            0, // x
            0, // y
            16, // width
            16, // height
            nullptr, // a handle to the parent window
            nullptr, // a handle to a menu
            nullptr, // a handle to the instance
            nullptr // custom parameter
        );

        if (!window_handle) {
            is_succeed = false;
        }
    }


    // Initialize OpenGL context
    //

    auto& wrapper = Wrapper::get_singleton();

    if (is_succeed) {
        is_succeed = wrapper.initialize_ogl_context(
            window_handle);
    }


    // Get OpenGL implementation dependant values
    //

    GLint max_texture_size = 0;

    if (is_succeed) {
        ::glGetIntegerv(
            GL_MAX_TEXTURE_SIZE,
            &max_texture_size);
    }


    GLint max_texture_image_units = 0;

    if (is_succeed) {
        ::glGetIntegerv(
            GL_MAX_TEXTURE_IMAGE_UNITS,
            &max_texture_image_units);
    }


    // Set Direct3D caps
    //

    if (is_succeed) {
        const DWORD filter_caps =
            D3DPTFILTERCAPS_MAGFANISOTROPIC |
            D3DPTFILTERCAPS_MINFANISOTROPIC;

        caps.DeviceType = D3DDEVTYPE_HAL;
        caps.AdapterOrdinal = D3DADAPTER_DEFAULT;
        caps.PresentationIntervals = D3DPRESENT_INTERVAL_ONE;
        caps.DevCaps = D3DDEVCAPS_HWTRANSFORMANDLIGHT;

        caps.RasterCaps =
            D3DPRASTERCAPS_FOGVERTEX |
            D3DPRASTERCAPS_ZFOG |
            D3DPRASTERCAPS_ZTEST;

        caps.SrcBlendCaps = D3DPBLENDCAPS_ONE;
        caps.DestBlendCaps = D3DPBLENDCAPS_ONE;

        caps.TextureCaps =
            D3DPTEXTURECAPS_ALPHA |
            D3DPTEXTURECAPS_MIPCUBEMAP |
            D3DPTEXTURECAPS_MIPMAP;

        caps.TextureFilterCaps = filter_caps;
        caps.MaxTextureWidth = static_cast<DWORD>(max_texture_size);
        caps.MaxTextureHeight = static_cast<DWORD>(max_texture_size);

        caps.TextureOpCaps =
            D3DTEXOPCAPS_ADD |
            D3DTEXOPCAPS_BLENDCURRENTALPHA |
            D3DTEXOPCAPS_BLENDFACTORALPHA |
            D3DTEXOPCAPS_BLENDTEXTUREALPHA |
            D3DTEXOPCAPS_MODULATE |
            D3DTEXOPCAPS_MODULATE2X |
            D3DTEXOPCAPS_SELECTARG1 |
            D3DTEXOPCAPS_SELECTARG2;

        caps.MaxTextureBlendStages = max_texture_image_units;
        caps.MaxVertexBlendMatrices = 4;
        caps.MaxVertexBlendMatrixIndex = max_world_matrices - 1;
        caps.VertexShaderVersion = D3DVS_VERSION(1, 1);
        caps.PixelShaderVersion = D3DVS_VERSION(1, 1);
        caps.MasterAdapterOrdinal = D3DADAPTER_DEFAULT;

        caps.VertexTextureFilterCaps = filter_caps;
    }


    // Clean up
    //

    wrapper.uninitialize_ogl_context();

    if (window_handle) {
        static_cast<void>(::DestroyWindow(
            window_handle));
    }

    if (window_class_id != 0) {
        static_cast<void>(::UnregisterClassW(
            reinterpret_cast<LPCWSTR>(static_cast<size_t>(window_class_id)),
            instance_handle));
    }


    if (is_succeed) {
        *caps_ptr = caps;
        return D3D_OK;
    }

    return D3DERR_INVALIDCALL;
}

HRESULT Device9Impl::d3d9_check_device_format(
    D3DDEVTYPE device_type,
    D3DFORMAT adapter_format,
    DWORD usage,
    D3DRESOURCETYPE resource_type,
    D3DFORMAT check_format)
{
    if (device_type != D3DDEVTYPE_HAL) {
        return D3DERR_INVALIDCALL;
    }

    const DWORD unsupported_usage_flags = (
        D3DUSAGE_DEPTHSTENCIL) ^ 0xFFFFFFFF;

    if ((usage & unsupported_usage_flags) != 0) {
        return D3DERR_INVALIDCALL;
    }

    switch (resource_type) {
    case D3DRTYPE_SURFACE:
        switch (check_format) {
        case D3DFMT_D24X8:
            if ((usage & D3DUSAGE_DEPTHSTENCIL) == 0) {
                return D3DERR_INVALIDCALL;
            }
            break;

        default:
            return D3DERR_INVALIDCALL;
        }
        break;

    case D3DRTYPE_TEXTURE:
        switch (check_format) {
        case D3DFMT_A8R8G8B8:
        case D3DFMT_X8R8G8B8:
        case D3DFMT_R8G8B8:
        case D3DFMT_A4R4G4B4:
        case D3DFMT_A1R5G5B5:
            break;

        default:
            return D3DERR_INVALIDCALL;
        }
        break;

    default:
        return D3DERR_INVALIDCALL;
    }

    return D3D_OK;
}

HRESULT Device9Impl::d3d9_check_device_type(
    D3DDEVTYPE device_type,
    D3DFORMAT adapter_format,
    D3DFORMAT back_buffer_format,
    BOOL windowed)
{
    if (device_type != D3DDEVTYPE_HAL) {
        return D3DERR_NOTAVAILABLE;
    }

    switch (adapter_format) {
    case D3DFMT_X8R8G8B8:
        break;

    default:
        return D3DERR_NOTAVAILABLE;
    }

    switch (back_buffer_format) {
    case D3DFMT_UNKNOWN:
        if (windowed == FALSE) {
            return D3DERR_NOTAVAILABLE;
        }
        break;

    case D3DFMT_X8R8G8B8:
        break;

    default:
        return D3DERR_NOTAVAILABLE;
    }

    return D3D_OK;
}

HRESULT Device9Impl::initialize(
    DWORD behavior_flags,
    const D3DPRESENT_PARAMETERS& presentation_parameters)
{
    if (!validate_behavior_flags(
        behavior_flags))
    {
        return D3DERR_INVALIDCALL;
    }

    if (!validate_presentation_parameters(
        presentation_parameters))
    {
        return D3DERR_INVALIDCALL;
    }

    auto is_succeed = true;

    if (is_succeed) {
        auto get_device_caps_result = d3d9_get_device_caps(
            D3DDEVTYPE_HAL,
            &d3d9_caps);

        is_succeed = (get_device_caps_result == D3D_OK);
    }

    auto& wrapper = Wrapper::get_singleton();

    if (is_succeed) {
        is_succeed = wrapper.initialize_ogl_context(
            presentation_parameters.hDeviceWindow);
    }

    if (is_succeed) {
        is_succeed = ogl_initialize_program();
    }

    if (is_succeed) {
        set_default_render_state();
        set_default_matrices();
    }

    if (is_succeed) {
        return D3D_OK;
    } else {
        uninitialize();
        return D3DERR_INVALIDCALL;
    }
}

void Device9Impl::uninitialize()
{
    ogl_uninitialize_program();
    ogl_uninitialize_shaders();


    auto& wrapper = Wrapper::get_singleton();

    wrapper.uninitialize_ogl_context();
}

void Device9Impl::set_default_render_state()
{
    render_state[D3DRS_ZENABLE] = TRUE;
    render_state[D3DRS_FILLMODE] = D3DFILL_SOLID;
    render_state[D3DRS_SHADEMODE] = D3DSHADE_GOURAUD;
    render_state[D3DRS_ZWRITEENABLE] = TRUE;
    render_state[D3DRS_ALPHATESTENABLE] = FALSE;
    render_state[D3DRS_SRCBLEND] = D3DBLEND_ONE;
    render_state[D3DRS_DESTBLEND] = D3DBLEND_ZERO;
    render_state[D3DRS_CULLMODE] = D3DCULL_CCW;
    render_state[D3DRS_ZFUNC] = TRUE;
    render_state[D3DRS_ALPHAREF] = 0;
    render_state[D3DRS_ALPHAFUNC] = D3DCMP_ALWAYS;
    render_state[D3DRS_DITHERENABLE] = FALSE;
    render_state[D3DRS_ALPHABLENDENABLE] = FALSE;
    render_state[D3DRS_FOGENABLE] = FALSE;
    render_state[D3DRS_SPECULARENABLE] = FALSE;
    render_state[D3DRS_FOGCOLOR] = 0;
    render_state[D3DRS_FOGTABLEMODE] = D3DFOG_NONE;
    render_state[D3DRS_FOGSTART] = float_to_dword(0.0F);
    render_state[D3DRS_FOGEND] = float_to_dword(1.0F);
    render_state[D3DRS_TEXTUREFACTOR] = 0xFFFFFFFF;
    render_state[D3DRS_CLIPPING] = TRUE;
    render_state[D3DRS_LIGHTING] = TRUE;
    render_state[D3DRS_AMBIENT] = 0;
    render_state[D3DRS_FOGVERTEXMODE] = D3DFOG_NONE;
    render_state[D3DRS_COLORVERTEX] = TRUE;
    render_state[D3DRS_NORMALIZENORMALS] = FALSE;
    render_state[D3DRS_DIFFUSEMATERIALSOURCE] = D3DMCS_COLOR1;
    render_state[D3DRS_SPECULARMATERIALSOURCE] = D3DMCS_COLOR2;
    render_state[D3DRS_AMBIENTMATERIALSOURCE] = D3DMCS_MATERIAL;
    render_state[D3DRS_EMISSIVEMATERIALSOURCE] = D3DMCS_MATERIAL;
    render_state[D3DRS_VERTEXBLEND] = D3DVBF_DISABLE;
    render_state[D3DRS_INDEXEDVERTEXBLENDENABLE] = FALSE;
    render_state[D3DRS_SLOPESCALEDEPTHBIAS] = 0;
    render_state[D3DRS_DEPTHBIAS] = 0;

    render_state_changes.set();
}

void Device9Impl::set_default_matrices()
{
    static_cast<void>(::D3DXMatrixIdentity(&view_matrix));
    view_matrix_changed = true;

    static_cast<void>(::D3DXMatrixIdentity(&projection_matrix));
    projection_matrix_changed = true;

    for (int i = 0; i < max_world_matrices; ++i) {
        static_cast<void>(::D3DXMatrixIdentity(&world_matrices[i]));
    }

    world_matrices_changes.set();
}

bool Device9Impl::validate_behavior_flags(
    DWORD flags)
{
    const DWORD unsupported_flags = (
        D3DCREATE_MULTITHREADED |
        D3DCREATE_MIXED_VERTEXPROCESSING) ^ 0xFFFFFFFF;

    if (flags == 0) {
        return false;
    }

    if ((flags & unsupported_flags) != 0) {
        return false;
    }

    return true;
}

bool Device9Impl::validate_presentation_parameters(
    const D3DPRESENT_PARAMETERS& presentation_parameters)
{
    auto& pp = presentation_parameters;

    switch (pp.BackBufferFormat) {
    case D3DFMT_UNKNOWN:
    case D3DFMT_X8R8G8B8:
        break;

    default:
        return false;
    }

    if (pp.BackBufferCount != 1) {
        return false;
    }

    if (pp.MultiSampleType != D3DMULTISAMPLE_NONE &&
        pp.SwapEffect != D3DSWAPEFFECT_DISCARD)
    {
        return false;
    }

    if (pp.SwapEffect != D3DSWAPEFFECT_COPY) {
        return false;
    }

    if (::IsWindow(pp.hDeviceWindow) == FALSE) {
        return false;
    }

    if (pp.EnableAutoDepthStencil == FALSE) {
        return false;
    }

    if (pp.AutoDepthStencilFormat != D3DFMT_D24X8) {
        return false;
    }

    if (pp.Flags != D3DPRESENTFLAG_LOCKABLE_BACKBUFFER) {
        return false;
    }

    return true;
}

void Device9Impl::validate_render_state_value(
    D3DRENDERSTATETYPE render_state_type,
    DWORD value)
{
    switch(render_state_type) {
    case D3DRS_ZENABLE:
        switch (value) {
        case D3DZB_FALSE:
        case D3DZB_TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_ZENABLE value.");
        }
        break;

    case D3DRS_FILLMODE:
        switch (value) {
        case D3DFILL_SOLID:
        case D3DFILL_WIREFRAME:
            break;

        default:
            throw Exception("Unsupported D3DRS_FILLMODE value.");
        }
        break;

    case D3DRS_SHADEMODE:
        switch (value) {
        case D3DSHADE_GOURAUD:
            break;

        default:
            throw Exception("Unsupported D3DRS_SHADEMODE value.");
        }
        break;

    case D3DRS_ZWRITEENABLE:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_ZWRITEENABLE value.");
        }
        break;

    case D3DRS_ALPHATESTENABLE:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_ALPHATESTENABLE value.");
        }
        break;

    case D3DRS_SRCBLEND:
        switch (value) {
        case D3DBLEND_DESTCOLOR:
        case D3DBLEND_INVDESTCOLOR:
        case D3DBLEND_ONE:
        case D3DBLEND_SRCALPHA:
        case D3DBLEND_ZERO:
            break;

        default:
            throw Exception("Unsupported D3DRS_SRCBLEND value.");
        }
        break;

    case D3DRS_DESTBLEND:
        switch (value) {
        case D3DBLEND_DESTCOLOR:
        case D3DBLEND_INVSRCALPHA:
        case D3DBLEND_INVSRCCOLOR:
        case D3DBLEND_INVDESTCOLOR:
        case D3DBLEND_ONE:
        case D3DBLEND_SRCCOLOR:
        case D3DBLEND_ZERO:
            break;

        default:
            throw Exception("Unsupported D3DRS_DESTBLEND value.");
        }
        break;

    case D3DRS_CULLMODE:
        switch (value) {
        case D3DCULL_NONE:
        case D3DCULL_CW:
        case D3DCULL_CCW:
            break;

        default:
            throw Exception("Unsupported D3DRS_CULLMODE value.");
        }
        break;

    case D3DRS_ZFUNC:
        switch (value) {
        case TRUE:
        case D3DCMP_ALWAYS:
        case D3DCMP_EQUAL:
        case D3DCMP_LESSEQUAL:
            break;

        default:
            throw Exception("Unsupported D3DRS_ZFUNC value.");
        }
        break;

    case D3DRS_ALPHAREF:
        if (value > 0xFF) {
            throw Exception("Unsupported D3DRS_ALPHAREF value.");
        }
        break;

    case D3DRS_ALPHAFUNC:
        switch (value) {
        case D3DCMP_ALWAYS:
        case D3DCMP_EQUAL:
        case D3DCMP_GREATEREQUAL:
        case D3DCMP_GREATER:
        case D3DCMP_LESS:
        case D3DCMP_LESSEQUAL:
        case D3DCMP_NOTEQUAL:
            break;

        default:
            throw Exception("Unsupported D3DRS_ALPHAFUNC value.");
        }
        break;

    case D3DRS_DITHERENABLE:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_DITHERENABLE value.");
        }
        break;

    case D3DRS_ALPHABLENDENABLE:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_ALPHABLENDENABLE value.");
        }
        break;

    case D3DRS_FOGENABLE:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_FOGENABLE value.");
        }
        break;

    case D3DRS_SPECULARENABLE:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_SPECULARENABLE value.");
        }
        break;

    case D3DRS_FOGCOLOR:
        break;

    case D3DRS_FOGTABLEMODE:
        switch (value) {
        case D3DFOG_NONE:
        case D3DFOG_LINEAR:
            break;

        default:
            throw Exception("Unsupported D3DRS_FOGTABLEMODE value.");
        }
        break;

    case D3DRS_FOGSTART:
        break;

    case D3DRS_FOGEND:
        break;

    case D3DRS_TEXTUREFACTOR:
        break;

    case D3DRS_CLIPPING:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_CLIPPING value.");
        }
        break;

    case D3DRS_LIGHTING:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_LIGHTING value.");
        }
        break;

    case D3DRS_AMBIENT:
        break;

    case D3DRS_FOGVERTEXMODE:
        switch (value) {
        case D3DFOG_NONE:
        case D3DFOG_LINEAR:
            break;

        default:
            throw Exception("Unsupported D3DRS_FOGVERTEXMODE value.");
        }
        break;

    case D3DRS_COLORVERTEX:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_COLORVERTEX value.");
        }
        break;

    case D3DRS_NORMALIZENORMALS:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_NORMALIZENORMALS value.");
        }
        break;

    case D3DRS_DIFFUSEMATERIALSOURCE:
        switch (value) {
        case D3DMCS_COLOR1:
        case D3DMCS_MATERIAL:
            break;

        default:
            throw Exception("Unsupported D3DRS_DIFFUSEMATERIALSOURCE value.");
        }
        break;

    case D3DRS_SPECULARMATERIALSOURCE:
        switch (value) {
        case D3DMCS_COLOR2:
        case D3DMCS_MATERIAL:
            break;

        default:
            throw Exception("Unsupported D3DRS_SPECULARMATERIALSOURCE value.");
        }
        break;

    case D3DRS_AMBIENTMATERIALSOURCE:
        switch (value) {
        case D3DMCS_MATERIAL:
            break;

        default:
            throw Exception("Unsupported D3DRS_AMBIENTMATERIALSOURCE value.");
        }
        break;

    case D3DRS_EMISSIVEMATERIALSOURCE:
        switch (value) {
        case D3DMCS_MATERIAL:
            break;

        default:
            throw Exception("Unsupported D3DRS_EMISSIVEMATERIALSOURCE value.");
        }
        break;

    case D3DRS_VERTEXBLEND:
        switch (value) {
        case D3DVBF_DISABLE:
        case D3DVBF_0WEIGHTS:
        case D3DVBF_1WEIGHTS:
        case D3DVBF_2WEIGHTS:
        case D3DVBF_3WEIGHTS:
            break;

        default:
            throw Exception("Unsupported D3DRS_VERTEXBLEND value.");
        }
        break;

    case D3DRS_INDEXEDVERTEXBLENDENABLE:
        switch (value) {
        case FALSE:
        case TRUE:
            break;

        default:
            throw Exception("Unsupported D3DRS_INDEXEDVERTEXBLENDENABLE value.");
        }
        break;

    case D3DRS_SLOPESCALEDEPTHBIAS:
        break;

    case D3DRS_DEPTHBIAS:
        break;

    default:
        throw Exception("Unsupported render state type.");
    }
}

DWORD Device9Impl::float_to_dword(
    const float value)
{
    return *reinterpret_cast<const DWORD*>(&value);
}

float Device9Impl::dword_to_float(
    const DWORD value)
{
    return *reinterpret_cast<const float*>(&value);
}

std::string Device9Impl::ogl_get_info_log(
    GLuint object)
{
    if (object == GL_NONE) {
        return std::string();
    }

    auto is_shader = false;
    GLint info_log_size = 0; // with a null terminator

    if (::glIsShader(object)) {
        is_shader = true;

        ::glGetShaderiv(
            object,
            GL_INFO_LOG_LENGTH,
            &info_log_size);
    } else if (::glIsProgram(object)) {
        is_shader = false;

        ::glGetProgramiv(
            object,
            GL_INFO_LOG_LENGTH,
            &info_log_size);
    }

    if (info_log_size <= 1) {
        return std::string();
    }

    GLsizei info_log_length; // without a null terminator

    std::vector<GLchar> info_log(
        info_log_size,
        '\0');

    if (is_shader) {
        ::glGetShaderInfoLog(
            object,
            info_log_size,
            &info_log_length,
            info_log.data());
    } else {
        ::glGetProgramInfoLog(
            object,
            info_log_size,
            &info_log_length,
            info_log.data());
    }

    if (info_log_length > 0) {
        return std::string(
            info_log.data(),
            info_log.size());
    }

    return std::string();
}

bool Device9Impl::ogl_create_shader(
    GLenum shader_type,
    const GLchar* const shader_text,
    GLuint& shader_object)
{
    auto& warning_message = ogl_get_shader_warning_message_ref(
        shader_type);

    const auto shader_type_name = ogl_get_shader_type_name(
        shader_type);

    shader_object = ::glCreateShader(
        shader_type);

    if (shader_object == GL_NONE) {
        ogl_error_message =
            "Failed to create a " + shader_type_name + " shader object.";

        return false;
    }

    GLint compile_status = GL_FALSE;

    const GLchar* const lines[1] = {
        shader_text,
    };

    const GLint lengths[1] = {
        static_cast<GLint>(
        std::string::traits_type::length(
            shader_text)),
    };

    ::glShaderSource(
        shader_object,
        1,
        lines,
        lengths);

    ::glCompileShader(
        shader_object);

    ::glGetShaderiv(
        shader_object,
        GL_COMPILE_STATUS,
        &compile_status);

    const auto shader_log = ogl_get_info_log(
        shader_object);

    if (compile_status != GL_FALSE) {
        if (!shader_log.empty()) {
            warning_message = shader_type_name + " shader:\n" + shader_log;
        }

        return true;
    }

    if (shader_log.empty()) {
        ogl_error_message = "Generic shader compiler error.";
    }

    ogl_error_message = shader_log;

    return false;
}

bool Device9Impl::ogl_initialize_program()
{
    ogl_error_message.clear();
    ogl_vertex_shader_warning_message.clear();
    ogl_fragment_shader_warning_message.clear();
    ogl_program_warning_message.clear();

    auto is_succeed = true;

    if (is_succeed) {
        is_succeed = ogl_create_shader(
            GL_VERTEX_SHADER,
            ogl_vertex_shader_source,
            ogl_vertex_shader_object);
    }

    if (is_succeed) {
        is_succeed = ogl_create_shader(
            GL_FRAGMENT_SHADER,
            ogl_fragment_shader_source,
            ogl_fragment_shader_object);
    }

    if (is_succeed) {
        ogl_program_object = ::glCreateProgram();

        if (ogl_program_object == GL_NONE) {
            is_succeed = false;
            ogl_error_message = "Failed to create a program object.";
        }
    }

    if (is_succeed) {
        GLint link_status = GL_FALSE;

        ::glAttachShader(
            ogl_program_object,
            ogl_vertex_shader_object);

        ::glAttachShader(
            ogl_program_object,
            ogl_fragment_shader_object);

        ::glLinkProgram(
            ogl_program_object);

        ::glGetProgramiv(
            ogl_program_object,
            GL_LINK_STATUS,
            &link_status);

        auto program_log = ogl_get_info_log(
            ogl_program_object);

        if (link_status != GL_FALSE) {
            if (!program_log.empty()) {
                ogl_program_warning_message = program_log;
            }
        } else {
            is_succeed = false;

            if (program_log.empty()) {
                program_log = "Generic program linker error.";
            }

            ogl_error_message = program_log;
        }

        is_succeed = (link_status != GL_FALSE);
    }

    return is_succeed;
}

void Device9Impl::ogl_uninitialize_program()
{
    if (ogl_program_object != GL_NONE) {
        ::glDeleteProgram(
            ogl_program_object);

        ogl_program_object = GL_NONE;
    }
}

void Device9Impl::ogl_uninitialize_shaders()
{
    if (ogl_vertex_shader_object != GL_NONE) {
        ::glDeleteShader(
            ogl_vertex_shader_object);

        ogl_vertex_shader_object = GL_NONE;
    }

    if (ogl_fragment_shader_object != GL_NONE) {
        ::glDeleteShader(
            ogl_fragment_shader_object);

        ogl_fragment_shader_object = GL_NONE;
    }
}

std::string Device9Impl::ogl_get_shader_type_name(
    GLenum shader_type)
{
    switch (shader_type) {
    case GL_VERTEX_SHADER:
        return "vertex";

    case GL_FRAGMENT_SHADER:
        return "fragment";

    default:
        throw Exception("Unsupported shader type.");
    }
}

std::string& Device9Impl::ogl_get_shader_warning_message_ref(
    GLenum shader_type)
{
    switch (shader_type) {
    case GL_VERTEX_SHADER:
        return ogl_vertex_shader_warning_message;

    case GL_FRAGMENT_SHADER:
        return ogl_fragment_shader_warning_message;

    default:
        throw Exception("Unsupported shader type.");
    }
}

// Internals
// =========


} // d3d9
} // ltjs
