#ifndef LTJS_D3D9_EXCEPTION_INCLUDED
#define LTJS_D3D9_EXCEPTION_INCLUDED


#include <exception>


namespace ltjs {
namespace d3d9 {


class Exception :
    public std::exception
{
public:
    Exception() noexcept;

    Exception(
        const char* message) noexcept;

    Exception(
        const Exception& that) noexcept;

    Exception& operator=(
        const Exception& that) noexcept;

    virtual ~Exception() noexcept;
}; // Exception


} // d3d9
} // ltjs


#endif // LTJS_D3D9_EXCEPTION_INCLUDED
