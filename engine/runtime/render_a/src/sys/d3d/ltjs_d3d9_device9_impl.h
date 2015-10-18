//
// Implementation of IDirect3DDevice9 via OpenGL
//


#ifndef LTJS_D3D9_DEVICE9_IMPL_INCLUDED
#define LTJS_D3D9_DEVICE9_IMPL_INCLUDED


#define GL_GLEXT_PROTOTYPES


#include <array>
#include <bitset>
#include <string>
#include <d3d9.h>
#include <d3dx9.h>
#include "GL/glcorearb.h"
#include "ltjs_d3d9_unknown_impl.h"


namespace ltjs {
namespace d3d9 {


class ID3d9Impl;


class Device9Impl :
    public IDirect3DDevice9,
    public UnknownImpl
{
public:
    // ========
    // IUnknown

    IFACEMETHODIMP QueryInterface(
        REFIID riid,
        void** ppvObj);

    IFACEMETHODIMP_(ULONG) AddRef();

    IFACEMETHODIMP_(ULONG) Release();

    // IUnknown
    // ========

    // ================
    // IDirect3DDevice9

    IFACEMETHODIMP TestCooperativeLevel();

    IFACEMETHODIMP_(UINT) GetAvailableTextureMem();

    IFACEMETHODIMP EvictManagedResources();

    IFACEMETHODIMP GetDirect3D(
        IDirect3D9** ppD3D9);

    IFACEMETHODIMP GetDeviceCaps(
        D3DCAPS9* pCaps);

    IFACEMETHODIMP GetDisplayMode(
        UINT iSwapChain,
        D3DDISPLAYMODE* pMode);

    IFACEMETHODIMP GetCreationParameters(
        D3DDEVICE_CREATION_PARAMETERS *pParameters);

    IFACEMETHODIMP SetCursorProperties(
        UINT XHotSpot,
        UINT YHotSpot,
        IDirect3DSurface9* pCursorBitmap);

    IFACEMETHODIMP_(void) SetCursorPosition(
        int X,
        int Y,
        DWORD Flags);

    IFACEMETHODIMP_(BOOL) ShowCursor(
        BOOL bShow);

    IFACEMETHODIMP CreateAdditionalSwapChain(
        D3DPRESENT_PARAMETERS* pPresentationParameters,
        IDirect3DSwapChain9** pSwapChain);

    IFACEMETHODIMP GetSwapChain(
        UINT iSwapChain,
        IDirect3DSwapChain9** pSwapChain);

    IFACEMETHODIMP_(UINT) GetNumberOfSwapChains();

    IFACEMETHODIMP Reset(
        D3DPRESENT_PARAMETERS* pPresentationParameters);

    IFACEMETHODIMP Present(
        const RECT* pSourceRect,
        const RECT* pDestRect,
        HWND hDestWindowOverride,
        const RGNDATA* pDirtyRegion);

    IFACEMETHODIMP GetBackBuffer(
        UINT iSwapChain,
        UINT iBackBuffer,
        D3DBACKBUFFER_TYPE Type,
        IDirect3DSurface9** ppBackBuffer);

    IFACEMETHODIMP GetRasterStatus(
        UINT iSwapChain,
        D3DRASTER_STATUS* pRasterStatus);

    IFACEMETHODIMP SetDialogBoxMode(
        BOOL bEnableDialogs);

    IFACEMETHODIMP_(void) SetGammaRamp(
        UINT iSwapChain,
        DWORD Flags,
        const D3DGAMMARAMP* pRamp);

    IFACEMETHODIMP_(void) GetGammaRamp(
        UINT iSwapChain,
        D3DGAMMARAMP* pRamp);

    IFACEMETHODIMP CreateTexture(
        UINT Width,
        UINT Height,
        UINT Levels,
        DWORD Usage,
        D3DFORMAT Format,
        D3DPOOL Pool,
        IDirect3DTexture9** ppTexture,
        HANDLE* pSharedHandle);

    IFACEMETHODIMP CreateVolumeTexture(
        UINT Width,
        UINT Height,
        UINT Depth,
        UINT Levels,
        DWORD Usage,
        D3DFORMAT Format,
        D3DPOOL Pool,
        IDirect3DVolumeTexture9** ppVolumeTexture,
        HANDLE* pSharedHandle);

    IFACEMETHODIMP CreateCubeTexture(
        UINT EdgeLength,
        UINT Levels,
        DWORD Usage,
        D3DFORMAT Format,
        D3DPOOL Pool,
        IDirect3DCubeTexture9** ppCubeTexture,
        HANDLE* pSharedHandle);

    IFACEMETHODIMP CreateVertexBuffer(
        UINT Length,
        DWORD Usage,
        DWORD FVF,
        D3DPOOL Pool,
        IDirect3DVertexBuffer9** ppVertexBuffer,
        HANDLE* pSharedHandle);

    IFACEMETHODIMP CreateIndexBuffer(
        UINT Length,
        DWORD Usage,
        D3DFORMAT Format,
        D3DPOOL Pool,
        IDirect3DIndexBuffer9** ppIndexBuffer,
        HANDLE* pSharedHandle);

    IFACEMETHODIMP CreateRenderTarget(
        UINT Width,
        UINT Height,
        D3DFORMAT Format,
        D3DMULTISAMPLE_TYPE MultiSample,
        DWORD MultisampleQuality,
        BOOL Lockable,
        IDirect3DSurface9** ppSurface,
        HANDLE* pSharedHandle);

    IFACEMETHODIMP CreateDepthStencilSurface(
        UINT Width,
        UINT Height,
        D3DFORMAT Format,
        D3DMULTISAMPLE_TYPE MultiSample,
        DWORD MultisampleQuality,
        BOOL Discard,
        IDirect3DSurface9** ppSurface,
        HANDLE* pSharedHandle);

    IFACEMETHODIMP UpdateSurface(
        IDirect3DSurface9* pSourceSurface,
        const RECT* pSourceRect,
        IDirect3DSurface9* pDestinationSurface,
        const POINT* pDestPoint);

    IFACEMETHODIMP UpdateTexture(
        IDirect3DBaseTexture9* pSourceTexture,
        IDirect3DBaseTexture9* pDestinationTexture);

    IFACEMETHODIMP GetRenderTargetData(
        IDirect3DSurface9* pRenderTarget,
        IDirect3DSurface9* pDestSurface);

    IFACEMETHODIMP GetFrontBufferData(
        UINT iSwapChain,
        IDirect3DSurface9* pDestSurface);

    IFACEMETHODIMP StretchRect(
        IDirect3DSurface9* pSourceSurface,
        const RECT* pSourceRect,
        IDirect3DSurface9* pDestSurface,
        const RECT* pDestRect,
        D3DTEXTUREFILTERTYPE Filter);

    IFACEMETHODIMP ColorFill(
        IDirect3DSurface9* pSurface,
        const RECT* pRect,
        D3DCOLOR color);

    IFACEMETHODIMP CreateOffscreenPlainSurface(
        UINT Width,
        UINT Height,
        D3DFORMAT Format,
        D3DPOOL Pool,
        IDirect3DSurface9** ppSurface,
        HANDLE* pSharedHandle);

    IFACEMETHODIMP SetRenderTarget(
        DWORD RenderTargetIndex,
        IDirect3DSurface9* pRenderTarget);

    IFACEMETHODIMP GetRenderTarget(
        DWORD RenderTargetIndex,
        IDirect3DSurface9** ppRenderTarget);

    IFACEMETHODIMP SetDepthStencilSurface(
        IDirect3DSurface9* pNewZStencil);

    IFACEMETHODIMP GetDepthStencilSurface(
        IDirect3DSurface9** ppZStencilSurface);

    IFACEMETHODIMP BeginScene();

    IFACEMETHODIMP EndScene();

    IFACEMETHODIMP Clear(
        DWORD Count,
        const D3DRECT* pRects,
        DWORD Flags,
        D3DCOLOR Color,
        float Z,
        DWORD Stencil);

    IFACEMETHODIMP SetTransform(
        D3DTRANSFORMSTATETYPE State,
        const D3DMATRIX* pMatrix);

    IFACEMETHODIMP GetTransform(
        D3DTRANSFORMSTATETYPE State,
        D3DMATRIX* pMatrix);

    IFACEMETHODIMP MultiplyTransform(
        D3DTRANSFORMSTATETYPE State,
        const D3DMATRIX* pMatrix);

    IFACEMETHODIMP SetViewport(
        const D3DVIEWPORT9* pViewport);

    IFACEMETHODIMP GetViewport(
        D3DVIEWPORT9* pViewport);

    IFACEMETHODIMP SetMaterial(
        const D3DMATERIAL9* pMaterial);

    IFACEMETHODIMP GetMaterial(
        D3DMATERIAL9* pMaterial);

    IFACEMETHODIMP SetLight(
        DWORD Index,
        const D3DLIGHT9* pLight);

    IFACEMETHODIMP GetLight(
        DWORD Index,
        D3DLIGHT9* pLight);

    IFACEMETHODIMP LightEnable(
        DWORD Index,
        BOOL Enable);

    IFACEMETHODIMP GetLightEnable(
        DWORD Index,
        BOOL* pEnable);

    IFACEMETHODIMP SetClipPlane(
        DWORD Index,
        const float* pPlane);

    IFACEMETHODIMP GetClipPlane(
        DWORD Index,
        float* pPlane);

    IFACEMETHODIMP SetRenderState(
        D3DRENDERSTATETYPE State,
        DWORD Value);

    IFACEMETHODIMP GetRenderState(
        D3DRENDERSTATETYPE State,
        DWORD* pValue);

    IFACEMETHODIMP CreateStateBlock(
        D3DSTATEBLOCKTYPE Type,
        IDirect3DStateBlock9** ppSB);

    IFACEMETHODIMP BeginStateBlock();

    IFACEMETHODIMP EndStateBlock(
        IDirect3DStateBlock9** ppSB);

    IFACEMETHODIMP SetClipStatus(
        const D3DCLIPSTATUS9* pClipStatus);

    IFACEMETHODIMP GetClipStatus(
        D3DCLIPSTATUS9* pClipStatus);

    IFACEMETHODIMP GetTexture(
        DWORD Stage,
        IDirect3DBaseTexture9** ppTexture);

    IFACEMETHODIMP SetTexture(
        DWORD Stage,
        IDirect3DBaseTexture9* pTexture);

    IFACEMETHODIMP GetTextureStageState(
        DWORD Stage,
        D3DTEXTURESTAGESTATETYPE Type,
        DWORD* pValue);

    IFACEMETHODIMP SetTextureStageState(
        DWORD Stage,
        D3DTEXTURESTAGESTATETYPE Type,
        DWORD Value);

    IFACEMETHODIMP GetSamplerState(
        DWORD Sampler,
        D3DSAMPLERSTATETYPE Type,
        DWORD* pValue);

    IFACEMETHODIMP SetSamplerState(
        DWORD Sampler,
        D3DSAMPLERSTATETYPE Type,
        DWORD Value);

    IFACEMETHODIMP ValidateDevice(
        DWORD* pNumPasses);

    IFACEMETHODIMP SetPaletteEntries(
        UINT PaletteNumber,
        const PALETTEENTRY* pEntries);

    IFACEMETHODIMP GetPaletteEntries(
        UINT PaletteNumber,
        PALETTEENTRY* pEntries);

    IFACEMETHODIMP SetCurrentTexturePalette(
        UINT PaletteNumber);

    IFACEMETHODIMP GetCurrentTexturePalette(
        UINT *PaletteNumber);

    IFACEMETHODIMP SetScissorRect(
        const RECT* pRect);

    IFACEMETHODIMP GetScissorRect(
        RECT* pRect);

    IFACEMETHODIMP SetSoftwareVertexProcessing(
        BOOL bSoftware);

    IFACEMETHODIMP_(BOOL) GetSoftwareVertexProcessing();

    IFACEMETHODIMP SetNPatchMode(
        float nSegments);

    IFACEMETHODIMP_(float) GetNPatchMode();

    IFACEMETHODIMP DrawPrimitive(
        D3DPRIMITIVETYPE PrimitiveType,
        UINT StartVertex,
        UINT PrimitiveCount);

    IFACEMETHODIMP DrawIndexedPrimitive(
        D3DPRIMITIVETYPE PrimitiveType,
        INT BaseVertexIndex,
        UINT MinVertexIndex,
        UINT NumVertices,
        UINT startIndex,
        UINT primCount);

    IFACEMETHODIMP DrawPrimitiveUP(
        D3DPRIMITIVETYPE PrimitiveType,
        UINT PrimitiveCount,
        const void* pVertexStreamZeroData,
        UINT VertexStreamZeroStride);

    IFACEMETHODIMP DrawIndexedPrimitiveUP(
        D3DPRIMITIVETYPE PrimitiveType,
        UINT MinVertexIndex,
        UINT NumVertices,
        UINT PrimitiveCount,
        const void* pIndexData,
        D3DFORMAT IndexDataFormat,
        const void* pVertexStreamZeroData,
        UINT VertexStreamZeroStride);

    IFACEMETHODIMP ProcessVertices(
        UINT SrcStartIndex,
        UINT DestIndex,
        UINT VertexCount,
        IDirect3DVertexBuffer9* pDestBuffer,
        IDirect3DVertexDeclaration9* pVertexDecl,
        DWORD Flags);

    IFACEMETHODIMP CreateVertexDeclaration(
        const D3DVERTEXELEMENT9* pVertexElements,
        IDirect3DVertexDeclaration9** ppDecl);

    IFACEMETHODIMP SetVertexDeclaration(
        IDirect3DVertexDeclaration9* pDecl);

    IFACEMETHODIMP GetVertexDeclaration(
        IDirect3DVertexDeclaration9** ppDecl);

    IFACEMETHODIMP SetFVF(
        DWORD FVF);

    IFACEMETHODIMP GetFVF(
        DWORD* pFVF);

    IFACEMETHODIMP CreateVertexShader(
        const DWORD* pFunction,
        IDirect3DVertexShader9** ppShader);

    IFACEMETHODIMP SetVertexShader(
        IDirect3DVertexShader9* pShader);

    IFACEMETHODIMP GetVertexShader(
        IDirect3DVertexShader9** ppShader);

    IFACEMETHODIMP SetVertexShaderConstantF(
        UINT StartRegister,
        const float* pConstantData,
        UINT Vector4fCount);

    IFACEMETHODIMP GetVertexShaderConstantF(
        UINT StartRegister,
        float* pConstantData,
        UINT Vector4fCount);

    IFACEMETHODIMP SetVertexShaderConstantI(
        UINT StartRegister,
        const int* pConstantData,
        UINT Vector4iCount);

    IFACEMETHODIMP GetVertexShaderConstantI(
        UINT StartRegister,
        int* pConstantData,
        UINT Vector4iCount);

    IFACEMETHODIMP SetVertexShaderConstantB(
        UINT StartRegister,
        const BOOL* pConstantData,
        UINT  BoolCount);

    IFACEMETHODIMP GetVertexShaderConstantB(
        UINT StartRegister,
        BOOL* pConstantData,
        UINT BoolCount);

    IFACEMETHODIMP SetStreamSource(
        UINT StreamNumber,
        IDirect3DVertexBuffer9* pStreamData,
        UINT OffsetInBytes, UINT Stride);

    IFACEMETHODIMP GetStreamSource(
        UINT StreamNumber,
        IDirect3DVertexBuffer9** ppStreamData,
        UINT* pOffsetInBytes,
        UINT* pStride);

    IFACEMETHODIMP SetStreamSourceFreq(
        UINT StreamNumber,
        UINT Setting);

    IFACEMETHODIMP GetStreamSourceFreq(
        UINT StreamNumber,
        UINT* pSetting);

    IFACEMETHODIMP SetIndices(
        IDirect3DIndexBuffer9* pIndexData);

    IFACEMETHODIMP GetIndices(
        IDirect3DIndexBuffer9** ppIndexData);

    IFACEMETHODIMP CreatePixelShader(
        const DWORD* pFunction,
        IDirect3DPixelShader9** ppShader);

    IFACEMETHODIMP SetPixelShader(
        IDirect3DPixelShader9* pShader);

    IFACEMETHODIMP GetPixelShader(
        IDirect3DPixelShader9** ppShader);

    IFACEMETHODIMP SetPixelShaderConstantF(
        UINT StartRegister,
        const float* pConstantData,
        UINT Vector4fCount);

    IFACEMETHODIMP GetPixelShaderConstantF(
        UINT StartRegister,
        float* pConstantData,
        UINT Vector4fCount);

    IFACEMETHODIMP SetPixelShaderConstantI(
        UINT StartRegister,
        const int* pConstantData,
        UINT Vector4iCount);

    IFACEMETHODIMP GetPixelShaderConstantI(
        UINT StartRegister,
        int* pConstantData,
        UINT Vector4iCount);

    IFACEMETHODIMP SetPixelShaderConstantB(
        UINT StartRegister,
        const BOOL* pConstantData,
        UINT  BoolCount);

    IFACEMETHODIMP GetPixelShaderConstantB(
        UINT StartRegister,
        BOOL* pConstantData,
        UINT BoolCount);

    IFACEMETHODIMP DrawRectPatch(
        UINT Handle,
        const float* pNumSegs,
        const D3DRECTPATCH_INFO* pRectPatchInfo);

    IFACEMETHODIMP DrawTriPatch(
        UINT Handle,
        const float* pNumSegs,
        const D3DTRIPATCH_INFO* pTriPatchInfo);

    IFACEMETHODIMP DeletePatch(
        UINT Handle);

    IFACEMETHODIMP CreateQuery(
        D3DQUERYTYPE Type,
        IDirect3DQuery9** ppQuery);

    // IDirect3DDevice9
    // ================


    // =========
    // Internals

    Device9Impl(
        ID3d9Impl* id3d9_impl);

    Device9Impl(
        const Device9Impl& that) = delete;

    Device9Impl& operator=(
        const Device9Impl& that) = delete;

    virtual ~Device9Impl();


    static HRESULT d3d9_get_adapter_identifier(
        DWORD flags,
        D3DADAPTER_IDENTIFIER9 *id_ptr);

    static HRESULT d3d9_get_adapter_display_mode(
        D3DDISPLAYMODE *mode_ptr);

    static UINT d3d9_get_adapter_mode_count(
        D3DFORMAT format);

    static HRESULT d3d9_enum_adapter_modes(
        D3DFORMAT format,
        UINT mode,
        D3DDISPLAYMODE* mode_ptr);

    static HRESULT d3d9_get_device_caps(
        D3DDEVTYPE device_type,
        D3DCAPS9* caps_ptr);

    static HRESULT d3d9_check_device_format(
        D3DDEVTYPE device_type,
        D3DFORMAT adapter_format,
        DWORD usage,
        D3DRESOURCETYPE resource_type,
        D3DFORMAT check_format);

    static HRESULT d3d9_check_device_type(
        D3DDEVTYPE device_type,
        D3DFORMAT adapter_format,
        D3DFORMAT back_buffer_format,
        BOOL windowed);


    HRESULT initialize(
        DWORD behavior_flags,
        const D3DPRESENT_PARAMETERS& presentation_parameters);

    void uninitialize();

    void set_default_render_state();

    void set_default_matrices();


    bool ogl_create_shader(
        GLenum shader_type,
        const GLchar* const shader_text,
        GLuint& shader_object);

    bool ogl_initialize_program();

    void ogl_uninitialize_program();

    void ogl_uninitialize_shaders();

    std::string& ogl_get_shader_warning_message_ref(
        GLenum shader_type);


    static bool validate_behavior_flags(
        DWORD flags);

    static bool validate_presentation_parameters(
        const D3DPRESENT_PARAMETERS& presentation_parameters);

    static DWORD float_to_dword(
        const float value);

    static float dword_to_float(
        const DWORD value);

    static std::string ogl_get_info_log(
        GLuint object);

    static std::string ogl_get_shader_type_name(
        GLenum shader_type);


    //
    static const int max_render_state = 256;
    static const int max_world_matrices = 256;

    static const GLchar* const ogl_vertex_shader_source;
    static const GLchar* const ogl_fragment_shader_source;

    using RenderState = std::array<DWORD,max_render_state>;
    using RenderStateChanges = std::bitset<max_render_state>;

    using WorldMatrices = std::array<D3DXMATRIX,max_world_matrices>;
    using WorldMatricesChanges = std::bitset<max_world_matrices>;


    ID3d9Impl* d3d9;
    D3DCAPS9 d3d9_caps;

    RenderState render_state;
    RenderStateChanges render_state_changes;

    D3DXMATRIX view_matrix;
    bool view_matrix_changed;

    D3DXMATRIX projection_matrix;
    bool projection_matrix_changed;

    WorldMatrices world_matrices;
    WorldMatricesChanges world_matrices_changes;

    std::string ogl_error_message;

    GLuint ogl_vertex_shader_object;
    std::string ogl_vertex_shader_warning_message;

    GLuint ogl_fragment_shader_object;
    std::string ogl_fragment_shader_warning_message;

    GLuint ogl_program_object;
    std::string ogl_program_warning_message;

    // Internals
    // =========
}; // Device9Impl


} // d3d9
} // ltjs


#endif // LTJS_D3D9_DEVICE9_IMPL_INCLUDED
