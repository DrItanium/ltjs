//
// Implementation of IDirect3DSurface9 via OpenGL
//


#ifndef LTJS_D3D9_SURFACE9_IMPL_INCLUDED
#define LTJS_D3D9_SURFACE9_IMPL_INCLUDED


#include <d3d9.h>
#include "ltjs_d3d9_unknown_impl.h"


namespace ltjs {
namespace d3d9 {


class Surface9Impl :
    public IDirect3DSurface9,
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

    // ==================
    // IDirect3DResource9

    IFACEMETHODIMP GetDevice(
        IDirect3DDevice9** ppDevice);

    IFACEMETHODIMP SetPrivateData(
        REFGUID refguid,
        const void* pData,
        DWORD SizeOfData,
        DWORD Flags);

    IFACEMETHODIMP GetPrivateData(
        REFGUID refguid,
        void* pData,
        DWORD* pSizeOfData);

    IFACEMETHODIMP FreePrivateData(
        REFGUID refguid);

    IFACEMETHODIMP_(DWORD) SetPriority(
        DWORD PriorityNew);

    IFACEMETHODIMP_(DWORD) GetPriority();

    IFACEMETHODIMP_(void) PreLoad();

    IFACEMETHODIMP_(D3DRESOURCETYPE) GetType();

    IFACEMETHODIMP GetContainer(
        REFIID riid,
        void** ppContainer);

    IFACEMETHODIMP GetDesc(
        D3DSURFACE_DESC *pDesc);

    IFACEMETHODIMP LockRect(
        D3DLOCKED_RECT* pLockedRect,
        const RECT* pRect,
        DWORD Flags);

    IFACEMETHODIMP UnlockRect();

    IFACEMETHODIMP GetDC(
        HDC *phdc);

    IFACEMETHODIMP ReleaseDC(
        HDC hdc);

    // IDirect3DResource9
    // ==================


    // =========
    // Internals

    Surface9Impl(
        IDirect3DDevice9* d3d9_device);

    Surface9Impl(
        const Surface9Impl& that) = delete;

    Surface9Impl& operator=(
        const Surface9Impl& that) = delete;

    virtual ~Surface9Impl();


private:
    IDirect3DDevice9* d3d9_device_;

    // Internals
    // =========
}; // Surface9Impl


} // d3d9
} // ltjs


#endif // LTJS_D3D9_SURFACE9_IMPL_INCLUDED
