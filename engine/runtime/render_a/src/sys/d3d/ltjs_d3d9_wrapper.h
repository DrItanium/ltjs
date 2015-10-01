//
// Direct3D wrapper
//


#ifndef LTJS_D3D9_WRAPPER_INCLUDED
#define LTJS_D3D9_WRAPPER_INCLUDED


#ifndef _WIN32
#error Cross-platform wrapper not implemented yet
#endif


#include <string>
#include <d3d9.h>


namespace ltjs {
namespace d3d9 {


class Wrapper {
public:
    enum class Mode
    {
        none,
        d3d9,
        ogl,
    }; // Mode


    Wrapper();

    Wrapper(
        const Wrapper& that) = delete;

    Wrapper& operator=(
        const Wrapper& that) = delete;

    ~Wrapper();


    bool initialize(
        Mode mode);

    bool initialize_ogl_context(
        HWND device_window);

    void uninitialize();

    void uninitialize_ogl_context();

    const std::string get_error_message();

    IDirect3D9* d3d_create9(
        UINT sdk_version);

    static Wrapper& get_singleton();


private:
    using FPDirect3DCreate9 = IDirect3D9* (WINAPI*)(
        UINT SDKVersion);


    bool initialize_d3d9();

    bool initialize_ogl();

    bool preinitialize_ogl_context(
        HWND device_window);

    void uninitialize_d3d9();

    void uninitialize_ogl();


    Mode mode_;
    HMODULE d3d9_module_;
    FPDirect3DCreate9 d3d_create9_;
    std::string error_message_;
}; // Wrapper


template<typename T>
union SymbolToFunction
{
public:
    explicit SymbolToFunction(
        void* symbol) :
        symbol_(symbol)
    {
    }

    operator T()
    {
        return function_;
    }

private:
    T function_;
    void* symbol_;
}; // SymbolToFunction


} // d3d9
} // ltjs


#endif // LTJS_D3D9_WRAPPER_INCLUDED
