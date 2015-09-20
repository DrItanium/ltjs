#include "precompile.h"
#include "ltjs_d3d9_surface9_impl.h"
#include "ltjs_d3d9_exception.h"


namespace ltjs {
namespace d3d9 {


// ========
// IUnknown

IFACEMETHODIMP Surface9Impl::QueryInterface(
    REFIID riid,
    void** ppvObj)
{
    return query_interface(
        IID_IDirect3DSurface9,
        riid,
        ppvObj);
}

IFACEMETHODIMP_(ULONG) Surface9Impl::AddRef()
{
    return add_ref();
}

IFACEMETHODIMP_(ULONG) Surface9Impl::Release()
{
    return release(
        this);
}

// IUnknown
// ========


// ==================
// IDirect3DResource9

IFACEMETHODIMP Surface9Impl::GetDevice(
    IDirect3DDevice9** ppDevice)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Surface9Impl::SetPrivateData(
    REFGUID refguid,
    const void* pData,
    DWORD SizeOfData,
    DWORD Flags)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Surface9Impl::GetPrivateData(
    REFGUID refguid,
    void* pData,
    DWORD* pSizeOfData)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Surface9Impl::FreePrivateData(
    REFGUID refguid)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) Surface9Impl::SetPriority(
    DWORD PriorityNew)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) Surface9Impl::GetPriority()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(void) Surface9Impl::PreLoad()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(D3DRESOURCETYPE) Surface9Impl::GetType()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Surface9Impl::GetContainer(
    REFIID riid,
    void** ppContainer)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Surface9Impl::GetDesc(
    D3DSURFACE_DESC *pDesc)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Surface9Impl::LockRect(
    D3DLOCKED_RECT* pLockedRect,
    const RECT* pRect,
    DWORD Flags)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Surface9Impl::UnlockRect()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Surface9Impl::GetDC(
    HDC *phdc)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Surface9Impl::ReleaseDC(
    HDC hdc)
{
    throw Exception("Not implemented.");
}

// IDirect3DResource9
// ==================


// =========
// Internals

Surface9Impl::Surface9Impl(
    IDirect3DDevice9* d3d9_device) :
        d3d9_device_(d3d9_device)
{
}

Surface9Impl::~Surface9Impl()
{
}

// Internals
// =========


} // d3d9
} // ltjs
