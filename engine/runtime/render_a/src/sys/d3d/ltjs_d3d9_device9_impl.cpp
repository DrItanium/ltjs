#include "precompile.h"
#include "ltjs_d3d9_device9_impl.h"
#include "ltjs_d3d9_exception.h"


namespace ltjs {
namespace d3d9 {


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
    throw Exception("Not implemented.");
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
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Device9Impl::GetRenderState(
    D3DRENDERSTATETYPE State,
    DWORD* pValue)
{
    throw Exception("Not implemented.");
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
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(BOOL) Device9Impl::GetSoftwareVertexProcessing()
{
    throw Exception("Not implemented.");
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

Device9Impl::Device9Impl()
{
}

Device9Impl::~Device9Impl()
{
}

HRESULT Device9Impl::initialize(
    DWORD behavior_flags,
    const D3DPRESENT_PARAMETERS& presentation_parameters)
{
    return D3DERR_NOTAVAILABLE;
}

void Device9Impl::uninitialize()
{
}

// Internals
// =========


} // d3d9
} // ltjs
