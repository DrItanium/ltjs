#include "precompile.h"
#include "ltjs_d3d9_vertex_buffer9_impl.h"
#include "ltjs_d3d9_exception.h"


namespace ltjs {
namespace d3d9 {


// ========
// IUnknown

IFACEMETHODIMP VertexBuffer9Impl::QueryInterface(
    REFIID riid,
    void** ppvObj)
{
    return query_interface(
        IID_IDirect3DVertexBuffer9,
        riid,
        ppvObj);
}

IFACEMETHODIMP_(ULONG) VertexBuffer9Impl::AddRef()
{
    return add_ref();
}

IFACEMETHODIMP_(ULONG) VertexBuffer9Impl::Release()
{
    return release(
        this);
}

// IUnknown
// ========


// ==================
// IDirect3DResource9

IFACEMETHODIMP VertexBuffer9Impl::GetDevice(
    IDirect3DDevice9** ppDevice)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP VertexBuffer9Impl::SetPrivateData(
    REFGUID refguid,
    const void* pData,
    DWORD SizeOfData,
    DWORD Flags)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP VertexBuffer9Impl::GetPrivateData(
    REFGUID refguid,
    void* pData,
    DWORD* pSizeOfData)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP VertexBuffer9Impl::FreePrivateData(
    REFGUID refguid)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) VertexBuffer9Impl::SetPriority(
    DWORD PriorityNew)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(DWORD) VertexBuffer9Impl::GetPriority()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(void) VertexBuffer9Impl::PreLoad()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP_(D3DRESOURCETYPE) VertexBuffer9Impl::GetType()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP VertexBuffer9Impl::Lock(
    UINT OffsetToLock,
    UINT SizeToLock,
    void** ppbData,
    DWORD Flags)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP VertexBuffer9Impl::Unlock()
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP VertexBuffer9Impl::GetDesc(
    D3DVERTEXBUFFER_DESC *pDesc)
{
    throw Exception("Not implemented.");
}

// IDirect3DResource9
// ==================


// =========
// Internals

VertexBuffer9Impl::VertexBuffer9Impl(
    IDirect3DDevice9* d3d9_device) :
        d3d9_device_(d3d9_device)
{
}

VertexBuffer9Impl::~VertexBuffer9Impl()
{
}

// Internals
// =========


} // d3d9
} // ltjs
