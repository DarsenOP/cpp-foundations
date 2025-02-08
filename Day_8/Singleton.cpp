//
// Created by DarsenOP on 2/8/25.
//

/* Classical Implementation */

/*#include <iostream>

class NaiveSingleton
{
    static NaiveSingleton* _instance;

    NaiveSingleton() {}
    NaiveSingleton(const NaiveSingleton&);
    NaiveSingleton& operator=(const NaiveSingleton&);

public:
    static NaiveSingleton* GetInstance()
    {
        if (!_instance) {
            _instance = new NaiveSingleton();
        }

        return _instance;
    }

    void do_it() const
    {
        std::cout << "Doing it" << std::endl;
    }
};

NaiveSingleton* NaiveSingleton::_instance = nullptr;*/

/* Implementation with Double Locking */

/*#include <mutex>
#include <iostream>

class DCLSingleton
{
    static DCLSingleton* _instance;

    DCLSingleton();
    DCLSingleton(const DCLSingleton&);
    DCLSingleton& operator=(const DCLSingleton&);

    static std::mutex mtx;

public:
    static DCLSingleton* GetInstance()
    {
        if (!_instance) {
            mtx.lock();
            if (!_instance) {
                _instance = new DCLSingleton();
            }
            mtx.unlock();
        }

        return _instance;
    }

    void do_it()
    {
        std::cout << "Do it" << std::endl;
    }
};

std::mutex DCLSingleton::mtx;
DCLSingleton* DCLSingleton::_instance = nullptr;*/

/* Meyers Implementation */

#include <iostream>
#include <ostream>

class MeyersSingletion
{
    MeyersSingletion() {}
    MeyersSingletion(const MeyersSingletion&);
    MeyersSingletion& operator=(const MeyersSingletion&);

public:
    static MeyersSingletion& GetInstance()
    {
        static MeyersSingletion _instance;
        return _instance;
    }

    void do_it()
    {
        std::cout << "do_it" << std::endl;
    }
};
