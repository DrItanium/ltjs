//
// Helper class to manage reference counter and to query interfaces
//


#ifndef LTJS_D3D9_UNKNOWN_IMPL_INCLUDED
#define LTJS_D3D9_UNKNOWN_IMPL_INCLUDED


#include <cassert>
#include <type_traits>
#include <d3d9.h>


namespace ltjs {
namespace d3d9 {


class UnknownImpl
{
public:
    UnknownImpl();

    UnknownImpl(
        const UnknownImpl& that) = delete;

    UnknownImpl& operator=(
        const UnknownImpl& that) = delete;

    ~UnknownImpl();


    UINT add_ref();

    template<typename T>
    UINT release(
        T* instance)
    {
        static_assert(
            std::is_base_of<UnknownImpl,T>::value,
            "Instance must be derived of UnknownImpl.");

        assert(ref_counter_ > 0);

        ref_counter_ -= 1;

        if (ref_counter_ == 0) {
            delete instance;
            return 0;
        }

        return ref_counter_;
    }

    HRESULT query_interface(
        REFIID iid_compare,
        REFIID riid,
        void** ppvObj);


protected:
    UINT ref_counter_;
}; // UnknownImpl


} // d3d9
} // ltjs


#endif // LTJS_D3D9_UNKNOWN_IMPL_INCLUDED
