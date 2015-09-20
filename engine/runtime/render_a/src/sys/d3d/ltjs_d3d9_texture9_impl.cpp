#include "precompile.h"
#include "ltjs_d3d9_texture9_impl.h"
#include "ltjs_d3d9_exception.h"


namespace ltjs {
namespace d3d9 {


// ========
// IUnknown

IFACEMETHODIMP Texture9Impl::QueryInterface(
    REFIID riid,
    void** ppvObj)
{
    return query_interface(
        IID_IDirect3DTexture9,
        riid,
        ppvObj);
}

IFACEMETHODIMP_(ULONG) Texture9Impl::AddRef()
{
    return add_ref();
}

IFACEMETHODIMP_(ULONG) Texture9Impl::Release()
{
    return release(
        this);
}

// IUnknown
// ========


// =====================
// IDirect3DBaseTexture9

IFACEMETHODIMP Texture9Impl::GetDevice(
    IDirect3DDevice9** ppDevice)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Texture9Impl::SetPrivateData(
    REFGUID refguid,
    const void* pData,
    DWORD SizeOfData,
    DWORD Flags)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Texture9Impl::GetPrivateData(
    REFGUID refguid,
    void* pData,
    DWORD* pSizeOfData)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Texture9Impl::FreePrivateData(
    REFGUID refguid)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) Texture9Impl::SetPriority(
    DWORD PriorityNew)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) Texture9Impl::GetPriority()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(void) Texture9Impl::PreLoad()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(D3DRESOURCETYPE) Texture9Impl::GetType()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) Texture9Impl::SetLOD(
    DWORD LODNew)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) Texture9Impl::GetLOD()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) Texture9Impl::GetLevelCount()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Texture9Impl::SetAutoGenFilterType(
    D3DTEXTUREFILTERTYPE FilterType)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(D3DTEXTUREFILTERTYPE) Texture9Impl::GetAutoGenFilterType()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(void) Texture9Impl::GenerateMipSubLevels()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Texture9Impl::GetLevelDesc(
    UINT Level,
    D3DSURFACE_DESC *pDesc)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Texture9Impl::GetSurfaceLevel(
    UINT Level,
    IDirect3DSurface9** ppSurfaceLevel)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Texture9Impl::LockRect(
    UINT Level,
    D3DLOCKED_RECT* pLockedRect,
    const RECT* pRect,
    DWORD Flags)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Texture9Impl::UnlockRect(
    UINT Level)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP Texture9Impl::AddDirtyRect(
    const RECT* pDirtyRect)
{
    throw Exception("Not implemented.");
}

// IDirect3DBaseTexture9
// =====================


// =========
// Internals

Texture9Impl::Texture9Impl(
    IDirect3DDevice9* d3d9_device) :
        d3d9_device_(d3d9_device)
{
}

Texture9Impl::~Texture9Impl()
{
}

// Internals
// =========


} // d3d9
} // ltjs
