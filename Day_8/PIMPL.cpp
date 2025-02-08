//
// Created by DarsenOP on 2/8/25.
//

#include <vector>

class Container
{
    Container (const Container& other);
    Container& operator =(const Container& other);

    class Impl;
    Impl* _impl;
public:
    explicit Container (const size_t size);

    int& operator [](const int index);
    const int& operator [](const int index) const;
};

class Container::Impl
{
public:
    explicit Impl (const size_t size)
    {
        vec.resize(size);
    }

    std::vector<int> vec;
};

Container::Container (const size_t size) : _impl(new Impl(size)) { }

int& Container::operator [](const int index) {
    return _impl->vec[index];
}

const int& Container::operator [](const int index) const {
    return _impl->vec[index];
}