#include "precompile.h"
#include <cassert>
#include "ltjs_d3d9_device_mutex_guard.h"


namespace ltjs {
namespace d3d9 {


DeviceMutexGuard::DeviceMutexGuard(
    DeviceMutex& mutex) :
    is_mutex_valid_(true),
    mutex_(mutex)
{
    mutex_.lock();

    mutex_.subscribe(
        &is_mutex_valid_);
}

DeviceMutexGuard::~DeviceMutexGuard()
{
    if (is_mutex_valid_) {
        mutex_.unsubscribe(
            &is_mutex_valid_);

        mutex_.unlock();
    }
}


} // d3d9
} // ltjs
