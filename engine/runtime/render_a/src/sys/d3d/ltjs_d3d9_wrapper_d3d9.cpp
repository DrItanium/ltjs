//
// Direct3D 9 wrapper
// Direct3D 9 parts
//


#include "precompile.h"
#include "ltjs_d3d9_wrapper.h"
#include <d3d9.h>


namespace ltjs {
namespace d3d9 {


bool Wrapper::initialize_d3d9()
{
    auto is_succeed = true;

    error_message_.empty();

    if (is_succeed) {
        d3d9_module_ = ::LoadLibraryW(L"d3d9.dll");

        if (!d3d9_module_) {
            is_succeed = false;
            error_message_ = "Failed to load Direct3D 9 library.";
        }
    }

    if (is_succeed) {
        d3d_create9_ = SymbolToFunction<FPDirect3DCreate9>(
            ::GetProcAddress(
                d3d9_module_,
                "Direct3DCreate9"));

        if (!d3d_create9_) {
            is_succeed = false;
            error_message_ = "Symbol Direct3DCreate not found.";
        }
    }

    if (is_succeed) {
        mode_ = Mode::d3d9;
    } else {
        uninitialize_d3d9();
    }

    return is_succeed;
}

void Wrapper::uninitialize_d3d9()
{
    if (d3d9_module_) {
        static_cast<void>(::FreeLibrary(d3d9_module_));
        d3d9_module_ = nullptr;
    }

    d3d_create9_ = nullptr;

    mode_ = Mode::none;
}


} // d3d9
} // ltjs
