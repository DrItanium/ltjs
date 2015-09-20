//
// Direct3D 9 wrapper
// Core parts
//


#include "precompile.h"
#include "ltjs_d3d9_wrapper.h"
#include <new>
#include <d3d9.h>
#include "ltjs_d3d9_id3d9_impl.h"


extern "C" IDirect3D9* WINAPI Direct3DCreate9(
    UINT SDKVersion)
{
    auto& wrapper = ltjs::d3d9::Wrapper::get_singleton();

    return wrapper.d3d_create9(
        SDKVersion);
}


namespace ltjs {
namespace d3d9 {


Wrapper::Wrapper() :
    error_message_(),
    d3d9_module_(),
    d3d_create9_()
{
}

Wrapper::~Wrapper()
{
    uninitialize();
}

bool Wrapper::initialize(
    Mode mode)
{
    switch (mode) {
    case Mode::d3d9:
        return initialize_d3d9();

    case Mode::ogl:
        return initialize_ogl();

    default:
        error_message_ = "Unsupported mode.";
        return false;
    }
}

const std::string Wrapper::get_error_message()
{
    return error_message_;
}

IDirect3D9* Wrapper::d3d_create9(
    UINT sdk_version)
{
    switch (mode_) {
    case Mode::d3d9:
        return d3d_create9_(
            sdk_version);

    case Mode::ogl:
        return new (std::nothrow) ID3d9Impl();

    default:
        return nullptr;
    }
}

Wrapper& Wrapper::get_singleton()
{
    static Wrapper wrapper;
    return wrapper;
}

void Wrapper::uninitialize()
{
    uninitialize_d3d9();
    uninitialize_ogl();
}


} // d3d9
} // ltjs
