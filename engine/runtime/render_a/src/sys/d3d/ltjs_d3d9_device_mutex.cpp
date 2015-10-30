#include "precompile.h"
#include <cassert>
#include "ltjs_d3d9_device_mutex.h"


namespace ltjs {
namespace d3d9 {


DeviceMutex::DeviceMutex() :
    ref_counter_(),
    mutex_(),
    subscribers_()
{
}

DeviceMutex::~DeviceMutex()
{
    for (auto subscriber : subscribers_) {
        *subscriber = false;
    }

    if (ref_counter_ > 0) {
        mutex_.unlock();
    }
}

void DeviceMutex::lock()
{
    if (ref_counter_ == 0) {
        mutex_.lock();
    }

    ref_counter_ += 1;
}

void DeviceMutex::unlock()
{
    ref_counter_ -= 1;

    if (ref_counter_ == 0) {
        mutex_.unlock();
    }
}

void DeviceMutex::subscribe(
    bool* is_mutex_valid_ptr)
{
    assert(is_mutex_valid_ptr);

    subscribers_.insert(
        is_mutex_valid_ptr);
}

void DeviceMutex::unsubscribe(
    bool* is_mutex_valid_ptr)
{
    assert(is_mutex_valid_ptr);

    subscribers_.erase(
        is_mutex_valid_ptr);
}


} // d3d9
} // ltjs
