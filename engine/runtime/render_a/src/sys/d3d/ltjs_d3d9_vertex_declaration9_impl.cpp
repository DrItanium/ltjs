#include "precompile.h"
#include "ltjs_d3d9_vertex_declaration9_impl.h"
#include "ltjs_d3d9_exception.h"


namespace ltjs {
namespace d3d9 {


// ========
// IUnknown

IFACEMETHODIMP VertexDeclaration9Impl::QueryInterface(
    REFIID riid,
    void** ppvObj)
{
    return query_interface(
        IID_IDirect3DVertexDeclaration9,
        riid,
        ppvObj);
}

IFACEMETHODIMP_(ULONG) VertexDeclaration9Impl::AddRef()
{
    return add_ref();
}

IFACEMETHODIMP_(ULONG) VertexDeclaration9Impl::Release()
{
    return release(
        this);
}

// IUnknown
// ========


// ===========================
// IDirect3DVertexDeclaration9

IFACEMETHODIMP VertexDeclaration9Impl::GetDevice(
    IDirect3DDevice9** ppDevice)
{
    throw Exception("Not implemented.");
}

IFACEMETHODIMP VertexDeclaration9Impl::GetDeclaration(
    D3DVERTEXELEMENT9* pElement,
    UINT* pNumElements)
{
    throw Exception("Not implemented.");
}

// IDirect3DVertexDeclaration9
// ===========================


// =========
// Internals

VertexDeclaration9Impl::VertexDeclaration9Impl(
    IDirect3DDevice9* d3d9_device) :
        d3d9_device_(d3d9_device)
{
}

VertexDeclaration9Impl::~VertexDeclaration9Impl()
{
}

// Internals
// =========


} // d3d9
} // ltjs
