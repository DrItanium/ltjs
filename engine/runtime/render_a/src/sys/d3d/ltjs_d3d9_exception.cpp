#include "precompile.h"
#include "ltjs_d3d9_exception.h"


namespace ltjs {
namespace d3d9 {


Exception::Exception() noexcept :
    std::exception()
{
}

Exception::Exception(
    const char* message) noexcept :
        std::exception(message)
{
}

Exception::Exception(
    const Exception& that) noexcept :
        std::exception(that)
{
}

Exception& Exception::operator=(
    const Exception& that) noexcept
{
    static_cast<void>(std::exception::operator=(that));

    return *this;
}

Exception::~Exception()
{
}


} // d3d9
} // ltjs
