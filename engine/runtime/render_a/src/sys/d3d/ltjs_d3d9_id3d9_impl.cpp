#include "precompile.h"


#define GL_GLEXT_PROTOTYPES


#include <new>
#include "GL/glcorearb.h"
#include "ltjs_d3d9_id3d9_impl.h"
#include "ltjs_d3d9_device9_impl.h"
#include "ltjs_d3d9_exception.h"
#include "ltjs_d3d9_wrapper.h"


namespace {


LRESULT CALLBACK DummyWindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam)
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
    return 1;
}

IFACEMETHODIMP ID3d9Impl::GetAdapterIdentifier(
    UINT Adapter,
    DWORD Flags,
    D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return D3DERR_INVALIDCALL;
    }

    return Device9Impl::d3d9_get_adapter_identifier(
        Flags,
        pIdentifier);
}

IFACEMETHODIMP_(UINT) ID3d9Impl::GetAdapterModeCount(
    UINT Adapter,
    D3DFORMAT Format)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return 0;
    }

    return Device9Impl::d3d9_get_adapter_mode_count(
        Format);
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

    return Device9Impl::d3d9_enum_adapter_modes(
        Format,
        Mode,
        pMode);
}

IFACEMETHODIMP ID3d9Impl::GetAdapterDisplayMode(
    UINT Adapter,
    D3DDISPLAYMODE* pMode)
{
    if (Adapter != D3DADAPTER_DEFAULT) {
        return D3DERR_INVALIDCALL;
    }

    return Device9Impl::d3d9_get_adapter_display_mode(
        pMode);
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

    return Device9Impl::d3d9_check_device_type(
        DevType,
        AdapterFormat,
        BackBufferFormat,
        bWindowed);
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

    return Device9Impl::d3d9_check_device_format(
        DeviceType,
        AdapterFormat,
        Usage,
        RType,
        CheckFormat);
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

    return Device9Impl::d3d9_get_device_caps(
        DeviceType,
        pCaps);
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
        D3DFMT_X8R8G8B8,
        pPresentationParameters->BackBufferFormat,
        pPresentationParameters->Windowed);

    if (check_device_type_result != D3D_OK) {
        return D3DERR_INVALIDCALL;
    }

    auto device = new (std::nothrow) Device9Impl(
        this);

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

ID3d9Impl::ID3d9Impl()
{
}

ID3d9Impl::~ID3d9Impl()
{
}

// Internals
// =========


} // d3d9
} // ltjs
