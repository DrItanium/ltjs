//
// Implementation of IDirect3D9 via OpenGL
//


#ifndef LTJS_D3D9_ID3D9_IMPL_INCLUDED
#define LTJS_D3D9_ID3D9_IMPL_INCLUDED


#include <d3d9.h>
#include "ltjs_d3d9_unknown_impl.h"


namespace ltjs {
namespace d3d9 {


class ID3d9Impl :
    public IDirect3D9,
    public UnknownImpl
{
public:
    // =======
    // IUnknown

    IFACEMETHODIMP QueryInterface(
        REFIID riid,
        void** ppvObj);

    IFACEMETHODIMP_(ULONG) AddRef();

    IFACEMETHODIMP_(ULONG) Release();

    // IUnknown
    // =======

    // ==========
    // IDirect3D9

    IFACEMETHODIMP RegisterSoftwareDevice(
        void* pInitializeFunction);

    IFACEMETHODIMP_(UINT) GetAdapterCount();

    IFACEMETHODIMP GetAdapterIdentifier(
        UINT Adapter,
        DWORD Flags,
        D3DADAPTER_IDENTIFIER9* pIdentifier);

    IFACEMETHODIMP_(UINT) GetAdapterModeCount(
        UINT Adapter,
        D3DFORMAT Format);

    IFACEMETHODIMP EnumAdapterModes(
        UINT Adapter,
        D3DFORMAT Format,
        UINT Mode,
        D3DDISPLAYMODE* pMode);

    IFACEMETHODIMP GetAdapterDisplayMode(
        UINT Adapter,
        D3DDISPLAYMODE* pMode);

    IFACEMETHODIMP CheckDeviceType(
        UINT Adapter,
        D3DDEVTYPE DevType,
        D3DFORMAT AdapterFormat,
        D3DFORMAT BackBufferFormat,
        BOOL bWindowed);

    IFACEMETHODIMP CheckDeviceFormat(
        UINT Adapter,
        D3DDEVTYPE DeviceType,
        D3DFORMAT AdapterFormat,
        DWORD Usage,
        D3DRESOURCETYPE RType,
        D3DFORMAT CheckFormat);

    IFACEMETHODIMP CheckDeviceMultiSampleType(
        UINT Adapter,
        D3DDEVTYPE DeviceType,
        D3DFORMAT SurfaceFormat,
        BOOL Windowed,
        D3DMULTISAMPLE_TYPE MultiSampleType,
        DWORD* pQualityLevels);

    IFACEMETHODIMP CheckDepthStencilMatch(
        UINT Adapter,
        D3DDEVTYPE DeviceType,
        D3DFORMAT AdapterFormat,
        D3DFORMAT RenderTargetFormat,
        D3DFORMAT DepthStencilFormat);

    IFACEMETHODIMP CheckDeviceFormatConversion(
        UINT Adapter,
        D3DDEVTYPE DeviceType,
        D3DFORMAT SourceFormat,
        D3DFORMAT TargetFormat);

    IFACEMETHODIMP GetDeviceCaps(
        UINT Adapter,
        D3DDEVTYPE DeviceType,
        D3DCAPS9* pCaps);

    IFACEMETHODIMP_(HMONITOR) GetAdapterMonitor(
        UINT Adapter);

    IFACEMETHODIMP CreateDevice(
        UINT Adapter,
        D3DDEVTYPE DeviceType,
        HWND hFocusWindow,
        DWORD BehaviorFlags,
        D3DPRESENT_PARAMETERS* pPresentationParameters,
        IDirect3DDevice9** ppReturnedDeviceInterface);

    // IDirect3D9
    // ==========


    // =========
    // Internals

    ID3d9Impl();

    ID3d9Impl(
        const ID3d9Impl& that) = delete;

    ID3d9Impl& operator=(
        const ID3d9Impl& that) = delete;

    virtual ~ID3d9Impl();

    // Internals
    // =========
}; // ID3d9Impl


} // d3d9
} // ltjs


#endif // LTJS_D3D9_ID3D9_IMPL_INCLUDED
