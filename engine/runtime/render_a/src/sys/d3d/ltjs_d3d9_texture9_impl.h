//
// Implementation of IDirect3DTexture9 via OpenGL
//


#ifndef LTJS_D3D9_TEXTURE9_IMPL_INCLUDED
#define LTJS_D3D9_TEXTURE9_IMPL_INCLUDED


#include <d3d9.h>
#include "ltjs_d3d9_unknown_impl.h"


namespace ltjs {
namespace d3d9 {


class Texture9Impl :
    public IDirect3DTexture9,
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

    // =====================
    // IDirect3DBaseTexture9

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

    IFACEMETHODIMP_(DWORD) SetLOD(
        DWORD LODNew);

    IFACEMETHODIMP_(DWORD) GetLOD();

    IFACEMETHODIMP_(DWORD) GetLevelCount();

    IFACEMETHODIMP SetAutoGenFilterType(
        D3DTEXTUREFILTERTYPE FilterType);

    IFACEMETHODIMP_(D3DTEXTUREFILTERTYPE) GetAutoGenFilterType();

    IFACEMETHODIMP_(void) GenerateMipSubLevels();

    IFACEMETHODIMP GetLevelDesc(
        UINT Level,
        D3DSURFACE_DESC *pDesc);

    IFACEMETHODIMP GetSurfaceLevel(
        UINT Level,
        IDirect3DSurface9** ppSurfaceLevel);

    IFACEMETHODIMP LockRect(
        UINT Level,
        D3DLOCKED_RECT* pLockedRect,
        const RECT* pRect,
        DWORD Flags);

    IFACEMETHODIMP UnlockRect(
        UINT Level);

    IFACEMETHODIMP AddDirtyRect(
        const RECT* pDirtyRect);

    // IDirect3DBaseTexture9
    // =====================


    // =========
    // Internals

    Texture9Impl(
        IDirect3DDevice9* d3d9_device);

    Texture9Impl(
        const Texture9Impl& that) = delete;

    Texture9Impl& operator=(
        const Texture9Impl& that) = delete;

    virtual ~Texture9Impl();


private:
    IDirect3DDevice9* d3d9_device_;

    // Internals
    // =========
}; // Texture9Impl


} // d3d9
} // ltjs


#endif // LTJS_D3D9_TEXTURE9_IMPL_INCLUDED
