#include "precompile.h"
#include "ltjs_d3d9_index_buffer9_impl.h"
#include "ltjs_d3d9_exception.h"


namespace ltjs {
namespace d3d9 {


// ========
// IUnknown

IFACEMETHODIMP IndexBuffer9Impl::QueryInterface(
    REFIID riid,
    void** ppvObj)
{
    return query_interface(
        IID_IDirect3DIndexBuffer9,
        riid,
        ppvObj);
}

IFACEMETHODIMP_(ULONG) IndexBuffer9Impl::AddRef()
{
    return add_ref();
}

IFACEMETHODIMP_(ULONG) IndexBuffer9Impl::Release()
{
    return release(
        this);
}

// IUnknown
// ========


// ==================
// IDirect3DResource9

IFACEMETHODIMP IndexBuffer9Impl::GetDevice(
    IDirect3DDevice9** ppDevice)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP IndexBuffer9Impl::SetPrivateData(
    REFGUID refguid,
    const void* pData,
    DWORD SizeOfData,
    DWORD Flags)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP IndexBuffer9Impl::GetPrivateData(
    REFGUID refguid,
    void* pData,
    DWORD* pSizeOfData)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP IndexBuffer9Impl::FreePrivateData(
    REFGUID refguid)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) IndexBuffer9Impl::SetPriority(
    DWORD PriorityNew)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) IndexBuffer9Impl::GetPriority()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(void) IndexBuffer9Impl::PreLoad()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(D3DRESOURCETYPE) IndexBuffer9Impl::GetType()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP IndexBuffer9Impl::Lock(
    UINT OffsetToLock,
    UINT SizeToLock,
    void** ppbData,
    DWORD Flags)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP IndexBuffer9Impl::Unlock()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP IndexBuffer9Impl::GetDesc(
    D3DINDEXBUFFER_DESC *pDesc)
{
    throw Exception("Not implemented.");
}

// IDirect3DResource9
// ==================


// =========
// Internals

IndexBuffer9Impl::IndexBuffer9Impl(
    IDirect3DDevice9* d3d9_device) :
        d3d9_device_(d3d9_device)
{
}

IndexBuffer9Impl::~IndexBuffer9Impl()
{
}

// Internals
// =========


} // d3d9
} // ltjs
