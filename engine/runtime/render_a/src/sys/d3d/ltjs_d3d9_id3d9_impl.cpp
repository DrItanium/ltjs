#include "precompile.h"
#include "ltjs_d3d9_id3d9_impl.h"
#include "ltjs_d3d9_exception.h"


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
    throw Exception("Not implemented.");
}

IFACEMETHODIMP ID3d9Impl::GetAdapterIdentifier(
    UINT Adapter,
    DWORD Flags,
    D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(UINT) ID3d9Impl::GetAdapterModeCount(
    UINT Adapter,
    D3DFORMAT Format)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP ID3d9Impl::EnumAdapterModes(
    UINT Adapter,
    D3DFORMAT Format,
    UINT Mode,
    D3DDISPLAYMODE* pMode)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP ID3d9Impl::GetAdapterDisplayMode(
    UINT Adapter,
    D3DDISPLAYMODE* pMode)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP ID3d9Impl::CheckDeviceType(
    UINT Adapter,
    D3DDEVTYPE DevType,
    D3DFORMAT AdapterFormat,
    D3DFORMAT BackBufferFormat,
    BOOL bWindowed)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP ID3d9Impl::CheckDeviceFormat(
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT AdapterFormat,
    DWORD Usage,
    D3DRESOURCETYPE RType,
    D3DFORMAT CheckFormat)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP ID3d9Impl::CheckDeviceMultiSampleType(
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT SurfaceFormat,
    BOOL Windowed,
    D3DMULTISAMPLE_TYPE MultiSampleType,
    DWORD* pQualityLevels)
{
    throw Exception("Not implemented.");
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
    throw Exception("Not implemented.");
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
    throw Exception("Not implemented.");
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
