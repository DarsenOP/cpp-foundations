//
// Created by DarsenOP on 2/8/25.
//

#include <iostream>
#include <mutex>
#include <exception>

class Lock
{
    std::mutex& mtx;
public:
    explicit Lock(std::mutex& m) : mtx(m)
    {
        std::cout << "Locking" << std::endl;
        mtx.lock();
    }

    ~Lock()
    {
        std::cout << "Unlocking" << std::endl;
        mtx.unlock();
    }
};

int main()
{
    std::mutex mt;

    std::cout << "Starting ..." << std::endl;

    try {
        Lock lock(mt);
        std::cout << "Doing stuff" << std::endl;
        throw std::exception();
    } catch (...) {
        std::cout << "Exception caught!" << std::endl;
    }

    std::cout << "Done!" << std::endl;
}