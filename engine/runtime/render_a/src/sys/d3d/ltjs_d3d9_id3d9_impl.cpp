#include "precompile.h"

#include <new>

#define GL_GLEXT_PROTOTYPES

#ifdef _WIN32
#include <windows.h>
#endif

#include "GL/glcorearb.h"
#include "ltjs_d3d9_id3d9_impl.h"
#include "ltjs_d3d9_device9_impl.h"
#include "ltjs_d3d9_exception.h"
#include "ltjs_d3d9_wrapper.h"


namespace {


LRESULT CALLBACK DummyWindowProc(
    _In_ HWND hwnd,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam)
{
    return ::DefWindowProcW(
        hwnd,
        uMsg,
        wParam,
        lParam);
}


} // namespace


namespace ltjs {
namespace d3d9 {


// ========
// IUnknown

IFACEMETHODIMP ID3d9Impl::QueryInterface(
    REFIID riid,
    void** ppvObj)
{
    return query_interface(
        IID_IDirect3D9,
        riid,
        ppvObj);
}

IFACEMETHODIMP_(ULONG) ID3d9Impl::AddRef()
{
    return add_ref();
}

IFACEMETHODIMP_(ULONG) ID3d9Impl::Release()
{
    return release(
        this);
}

// IUnknown
// ========

// ==========
// IDirect3D9

IFACEMETHODIMP ID3d9Impl::RegisterSoftwareDevice(
    void* pInitializeFunction)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(UINT) ID3d9Impl::GetAdapterCount()
{
    return (has_adapter_ ? 1 : 0);
}

IFACEMETHODIMP ID3d9Impl::GetAdapterIdentifier(
    UINT Adapter,
    DWORD Flags,
    D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return D3DERR_INVALIDCALL;
    }

    if (!pIdentifier) {
        return D3DERR_INVALIDCALL;
    }

    if (!has_adapter_) {
        return D3DERR_INVALIDCALL;
    }

    *pIdentifier = adapterId_;

    return D3D_OK;
}

IFACEMETHODIMP_(UINT) ID3d9Impl::GetAdapterModeCount(
    UINT Adapter,
    D3DFORMAT Format)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return 0;
    }

    if (Format != D3DFMT_A8R8G8B8) {
        return 0;
    }

    if (!has_adapter_) {
        return 0;
    }

    return static_cast<UINT>(displayModes_.size());
}

IFACEMETHODIMP ID3d9Impl::EnumAdapterModes(
    UINT Adapter,
    D3DFORMAT Format,
    UINT Mode,
    D3DDISPLAYMODE* pMode)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return D3DERR_INVALIDCALL;
    }

    if (Format != D3DFMT_A8R8G8B8) {
        return D3DERR_INVALIDCALL;
    }

    if (Mode >= static_cast<UINT>(displayModes_.size())) {
        return D3DERR_INVALIDCALL;
    }

    if (!pMode) {
        return D3DERR_INVALIDCALL;
    }

    if (!has_adapter_) {
        return D3DERR_INVALIDCALL;
    }

    *pMode = displayModes_[Mode];

    return D3D_OK;
}

IFACEMETHODIMP ID3d9Impl::GetAdapterDisplayMode(
    UINT Adapter,
    D3DDISPLAYMODE* pMode)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return D3DERR_INVALIDCALL;
    }

    if (!pMode) {
        return D3DERR_INVALIDCALL;
    }

    if (!has_adapter_) {
        return D3DERR_INVALIDCALL;
    }

    *pMode = displayModes_[currentDisplayModeIndex_];

    return D3D_OK;
}

IFACEMETHODIMP ID3d9Impl::CheckDeviceType(
    UINT Adapter,
    D3DDEVTYPE DevType,
    D3DFORMAT AdapterFormat,
    D3DFORMAT BackBufferFormat,
    BOOL bWindowed)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return D3DERR_INVALIDCALL;
    }

    if (DevType != D3DDEVTYPE_HAL) {
        return D3DERR_NOTAVAILABLE;
    }

    switch (AdapterFormat) {
    case D3DFMT_A8R8G8B8:
    case D3DFMT_X8R8G8B8:
        break;

    default:
        return D3DERR_NOTAVAILABLE;
    }

    switch (BackBufferFormat) {
    case D3DFMT_A8R8G8B8:
    case D3DFMT_X8R8G8B8:
        break;

    default:
        return D3DERR_NOTAVAILABLE;
    }

    return D3D_OK;
}

IFACEMETHODIMP ID3d9Impl::CheckDeviceFormat(
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT AdapterFormat,
    DWORD Usage,
    D3DRESOURCETYPE RType,
    D3DFORMAT CheckFormat)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return D3DERR_INVALIDCALL;
    }

    if (DeviceType != D3DDEVTYPE_HAL) {
        return D3DERR_INVALIDCALL;
    }

    switch (RType) {
    case D3DRTYPE_SURFACE:
        if (CheckFormat != D3DFMT_D24S8) {
            return D3DERR_INVALIDCALL;
        }
        break;

    case D3DRTYPE_TEXTURE:
        switch (CheckFormat) {
        case D3DFMT_A8R8G8B8:
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

IFACEMETHODIMP ID3d9Impl::CheckDeviceMultiSampleType(
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT SurfaceFormat,
    BOOL Windowed,
    D3DMULTISAMPLE_TYPE MultiSampleType,
    DWORD* pQualityLevels)
{
    static_cast<void>(Adapter);
    static_cast<void>(DeviceType);
    static_cast<void>(SurfaceFormat);
    static_cast<void>(Windowed);
    static_cast<void>(MultiSampleType);
    static_cast<void>(pQualityLevels);

    // FIXME

    return D3DERR_NOTAVAILABLE;
}

IFACEMETHODIMP ID3d9Impl::CheckDepthStencilMatch(
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT AdapterFormat,
    D3DFORMAT RenderTargetFormat,
    D3DFORMAT DepthStencilFormat)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP ID3d9Impl::CheckDeviceFormatConversion(
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT SourceFormat,
    D3DFORMAT TargetFormat)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP ID3d9Impl::GetDeviceCaps(
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DCAPS9* pCaps)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return D3DERR_INVALIDDEVICE;
    }

    if (DeviceType != D3DDEVTYPE_HAL) {
        return D3DERR_NOTAVAILABLE;
    }

    if (!pCaps) {
        return D3DERR_INVALIDCALL;
    }

    *pCaps = caps_;

    return D3D_OK;
}

IFACEMETHODIMP_(HMONITOR) ID3d9Impl::GetAdapterMonitor(
    UINT Adapter)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP ID3d9Impl::CreateDevice(
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    HWND hFocusWindow,
    DWORD BehaviorFlags,
    D3DPRESENT_PARAMETERS* pPresentationParameters,
    IDirect3DDevice9** ppReturnedDeviceInterface)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return D3DERR_INVALIDCALL;
    }

    if (DeviceType != D3DDEVTYPE_HAL) {
        return D3DERR_INVALIDCALL;
    }

    if (!pPresentationParameters) {
        return D3DERR_INVALIDCALL;
    }

    if (!ppReturnedDeviceInterface) {
        return D3DERR_INVALIDCALL;
    }

    auto check_device_type_result = CheckDeviceType(
        Adapter,
        DeviceType,
        D3DFMT_A8R8G8B8,
        pPresentationParameters->BackBufferFormat,
        pPresentationParameters->Windowed);

    if (check_device_type_result != D3D_OK) {
        return D3DERR_INVALIDCALL;
    }

    auto device =
        new (std::nothrow) Device9Impl();

    if (!device) {
        return D3DERR_OUTOFVIDEOMEMORY;
    }

    auto initialize_result = device->initialize(
        BehaviorFlags,
        *pPresentationParameters);

    if (initialize_result == D3D_OK) {
        *ppReturnedDeviceInterface =
            static_cast<IDirect3DDevice9*>(device);
    } else {
        static_cast<void>(device->Release());
    }

    return initialize_result;
}

// IDirect3D9
// ==========


// =========
// Internals

ID3d9Impl::ID3d9Impl() :
    has_adapter_(),
    adapterId_(),
    displayModes_(),
    currentDisplayModeIndex_(),
    caps_()
{
    initialize();
}

ID3d9Impl::~ID3d9Impl()
{
}

void ID3d9Impl::initialize()
{
    initialize_adapter_id();
    initialize_display_modes();
    initialize_caps();
}

void ID3d9Impl::initialize_adapter_id()
{
    auto driver_name = "";
    auto description = "Primary Display Driver";
    auto device_name = "\\\\.\\DISPLAY1";

    D3DADAPTER_IDENTIFIER9 dai{};

    std::string::traits_type::copy(
        dai.Driver,
        driver_name,
        std::string::traits_type::length(
            driver_name)
    );

    std::string::traits_type::copy(
        dai.Description,
        description,
        std::string::traits_type::length(
            description)
    );

    std::string::traits_type::copy(
        dai.DeviceName,
        device_name,
        std::string::traits_type::length(
            device_name)
    );
}

void ID3d9Impl::initialize_display_modes()
{
    has_adapter_ = false;

    displayModes_.clear();
    currentDisplayModeIndex_ = -1;


    // Get current display mode
    //

    D3DDISPLAYMODE currentDisplayMode{};

    DEVMODEA cdm{};
    cdm.dmSize = sizeof(decltype(cdm));

    auto enum_display_settings_result = ::EnumDisplaySettingsA(
        nullptr,
        ENUM_CURRENT_SETTINGS,
        &cdm
    );

    if (enum_display_settings_result != FALSE) {
        currentDisplayMode.Width = cdm.dmPelsWidth;
        currentDisplayMode.Height = cdm.dmPelsHeight;
        currentDisplayMode.RefreshRate = cdm.dmDisplayFrequency;

        if (cdm.dmBitsPerPel == 32) {
            currentDisplayMode.Format = D3DFMT_A8R8G8B8;
        } else {
            currentDisplayMode.Format = D3DFMT_UNKNOWN;
        }
    }


    // Get all display modes
    //

    auto was_found_current_mode_index = false;

    for (DWORD i = 0; ; ++i) {
        DEVMODEA dm;
        dm.dmSize = sizeof(decltype(dm));

        enum_display_settings_result = ::EnumDisplaySettingsA(
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


        displayModes_.emplace_back();

        auto& displayMode = displayModes_.back();

        displayMode.Width = dm.dmPelsWidth;
        displayMode.Height = dm.dmPelsHeight;
        displayMode.RefreshRate = dm.dmDisplayFrequency;
        displayMode.Format = D3DFMT_A8R8G8B8;

        if (!was_found_current_mode_index) {
            if (currentDisplayMode.Width == displayMode.Width &&
                currentDisplayMode.Height == displayMode.Height &&
                currentDisplayMode.RefreshRate == displayMode.RefreshRate &&
                currentDisplayMode.Format == displayMode.Format)
            {
                was_found_current_mode_index = true;
                currentDisplayModeIndex_ = static_cast<int>(i);
            }
        }
    }

    if (!displayModes_.empty() &&
        currentDisplayModeIndex_ >= 0)
    {
        has_adapter_ = true;
    } else {
        displayModes_.clear();
        currentDisplayModeIndex_ = -1;
    }
}

void ID3d9Impl::initialize_caps()
{
    auto is_succeed = true;

    auto instance_handle =
        ::GetModuleHandleW(nullptr);


    // Register window class
    //

    ATOM window_class_id = 0;

    if (is_succeed) {
        WNDCLASSEXW wce{};
        wce.cbSize = sizeof(decltype(wce));
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
            D3DPTFILTERCAPS_MINFANISOTROPIC
        ;

        caps_ = D3DCAPS9{};
        caps_.DeviceType = D3DDEVTYPE_HAL;
        caps_.AdapterOrdinal = D3DADAPTER_DEFAULT;
        caps_.PresentationIntervals = D3DPRESENT_INTERVAL_ONE;
        caps_.DevCaps = D3DDEVCAPS_HWTRANSFORMANDLIGHT;

        caps_.RasterCaps =
            D3DPRASTERCAPS_FOGVERTEX |
            D3DPRASTERCAPS_ZFOG |
            D3DPRASTERCAPS_ZTEST
        ;

        caps_.SrcBlendCaps = D3DPBLENDCAPS_ONE;
        caps_.DestBlendCaps = D3DPBLENDCAPS_ONE;

        caps_.TextureCaps =
            D3DPTEXTURECAPS_ALPHA |
            D3DPTEXTURECAPS_MIPCUBEMAP |
            D3DPTEXTURECAPS_MIPMAP
        ;

        caps_.TextureFilterCaps = filter_caps;
        caps_.MaxTextureWidth = static_cast<DWORD>(max_texture_size);
        caps_.MaxTextureHeight = static_cast<DWORD>(max_texture_size);

        caps_.TextureOpCaps =
            D3DTEXOPCAPS_ADD |
            D3DTEXOPCAPS_BLENDCURRENTALPHA |
            D3DTEXOPCAPS_BLENDFACTORALPHA |
            D3DTEXOPCAPS_BLENDTEXTUREALPHA |
            D3DTEXOPCAPS_MODULATE |
            D3DTEXOPCAPS_MODULATE2X |
            D3DTEXOPCAPS_SELECTARG1 |
            D3DTEXOPCAPS_SELECTARG2
        ;

        caps_.MaxTextureBlendStages = max_texture_image_units;
        caps_.MaxVertexBlendMatrices = 4;
        caps_.MaxVertexBlendMatrixIndex = 255;
        caps_.VertexShaderVersion = D3DVS_VERSION(1, 1);
        caps_.PixelShaderVersion = D3DVS_VERSION(1, 1);
        caps_.MasterAdapterOrdinal = D3DADAPTER_DEFAULT;

        caps_.VertexTextureFilterCaps = filter_caps;
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


    if (!is_succeed) {
        caps_ = D3DCAPS9{};
    }
}

// Internals
// =========


} // d3d9
} // ltjs
