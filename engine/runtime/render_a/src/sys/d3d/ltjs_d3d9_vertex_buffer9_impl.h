//
// Implementation of IDirect3DVertexBuffer9 via OpenGL
//


#ifndef LTJS_D3D9_VERTEX_BUFFER9_IMPL_INCLUDED
#define LTJS_D3D9_VERTEX_BUFFER9_IMPL_INCLUDED


#include <d3d9.h>
#include "ltjs_d3d9_unknown_impl.h"


namespace ltjs {
namespace d3d9 {


class VertexBuffer9Impl :
    public IDirect3DVertexBuffer9,
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

    IFACEMETHODIMP Lock(
        UINT OffsetToLock,
        UINT SizeToLock,
        void** ppbData,
        DWORD Flags);

    IFACEMETHODIMP Unlock();

    IFACEMETHODIMP GetDesc(
        D3DVERTEXBUFFER_DESC *pDesc);

    // IDirect3DResource9
    // ==================


    // =========
    // Internals

    VertexBuffer9Impl(
        IDirect3DDevice9* d3d9_device);

    VertexBuffer9Impl(
        const VertexBuffer9Impl& that) = delete;

    VertexBuffer9Impl& operator=(
        const VertexBuffer9Impl& that) = delete;

    virtual ~VertexBuffer9Impl();


private:
    IDirect3DDevice9* d3d9_device_;

    // Internals
    // =========
}; // VertexBuffer9Impl


} // d3d9
} // ltjs


#endif // LTJS_D3D9_VERTEX_BUFFER9_IMPL_INCLUDED
