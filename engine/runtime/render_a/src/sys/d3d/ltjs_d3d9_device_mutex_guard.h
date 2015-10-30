#ifndef LTJS_D3D9_DEVICE_MUTEX_GUARD_INCLUDED
#define LTJS_D3D9_DEVICE_MUTEX_GUARD_INCLUDED


#include "ltjs_d3d9_device_mutex.h"


namespace ltjs {
namespace d3d9 {


class DeviceMutexGuard {
public:
    DeviceMutexGuard(
        DeviceMutex& mutex);

    DeviceMutexGuard(
        const DeviceMutexGuard& that) = delete;

    DeviceMutexGuard& operator=(
        const DeviceMutexGuard& that) = delete;

    ~DeviceMutexGuard();


private:
    bool is_mutex_valid_;
    DeviceMutex& mutex_;
}; // DeviceMutex


} // d3d9
} // ltjs


#endif // LTJS_D3D9_DEVICE_MUTEX_GUARD_INCLUDED
