#ifndef LTJS_D3D9_DEVICE_MUTEX_INCLUDED
#define LTJS_D3D9_DEVICE_MUTEX_INCLUDED


#include <mutex>
#include <unordered_set>


namespace ltjs {
namespace d3d9 {


class DeviceMutex {
public:
    DeviceMutex();

    DeviceMutex(
        const DeviceMutex& that) = delete;

    DeviceMutex& operator=(
        const DeviceMutex& that) = delete;

    ~DeviceMutex();


    void lock();

    void unlock();


    void subscribe(
        bool* is_mutex_valid_ptr);

    void unsubscribe(
        bool* is_mutex_valid_ptr);


private:
    using Subscribers = std::unordered_set<bool*>;

    int ref_counter_;
    std::mutex mutex_;
    Subscribers subscribers_;
}; // DeviceMutex


} // d3d9
} // ltjs


#endif // LTJS_D3D9_DEVICE_MUTEX_INCLUDED
