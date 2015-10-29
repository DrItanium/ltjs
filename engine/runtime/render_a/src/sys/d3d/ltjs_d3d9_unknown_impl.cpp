#include "precompile.h"
#include "ltjs_d3d9_unknown_impl.h"


namespace ltjs {
namespace d3d9 {


UnknownImpl::UnknownImpl() :
    ref_counter_(1),
    is_releasing_()
{
}

UnknownImpl::~UnknownImpl()
{
    assert(ref_counter_ == 0);
}

UINT UnknownImpl::add_ref()
{
    ref_counter_ += 1;
    return ref_counter_;
}

HRESULT UnknownImpl::query_interface(
    REFIID iid_compare,
    REFIID riid,
    void** ppvObj)
{
    if (!ppvObj) {
        return E_POINTER;
    }

    *ppvObj = nullptr;

    if (riid == IID_IUnknown || riid == iid_compare) {
        static_cast<void>(add_ref());
        *ppvObj = this;
        return S_OK;
    }

    return E_NOINTERFACE;
}


} // d3d9
} // ltjs
