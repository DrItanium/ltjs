//
// Implementation of IDirect3DVertexDeclaration9 via OpenGL
//


#ifndef LTJS_D3D9_VERTEX_DECLARATION9_IMPL_INCLUDED
#define LTJS_D3D9_VERTEX_DECLARATION9_IMPL_INCLUDED


#include <d3d9.h>
#include "ltjs_d3d9_unknown_impl.h"


namespace ltjs {
namespace d3d9 {


class VertexDeclaration9Impl :
    public IDirect3DVertexDeclaration9,
    public UnknownImpl
{
public:
    // ========
    // IUnknown

    IFACEMETHODIMP QueryInterface(
        REFIID riid,
        void** ppvObj);

    IFACEMETHODIMP_(ULONG) AddRef();

    IFACEMETHODIMP_(ULONG) Release();

    // IUnknown
    // ========

    // ===========================
    // IDirect3DVertexDeclaration9

    IFACEMETHODIMP GetDevice(
        IDirect3DDevice9** ppDevice);

    IFACEMETHODIMP GetDeclaration(
        D3DVERTEXELEMENT9* pElement,
        UINT* pNumElements);

    // IDirect3DVertexDeclaration9
    // ===========================


    // =========
    // Internals

    VertexDeclaration9Impl(
        IDirect3DDevice9* d3d9_device);

    VertexDeclaration9Impl(
        const VertexDeclaration9Impl& that) = delete;

    VertexDeclaration9Impl& operator=(
        const VertexDeclaration9Impl& that) = delete;

    virtual ~VertexDeclaration9Impl();


private:
    IDirect3DDevice9* d3d9_device_;

    // Internals
    // =========
}; // VertexDeclaration9Impl


} // d3d9
} // ltjs


#endif // LTJS_D3D9_VERTEX_DECLARATION9_IMPL_INCLUDED
