//
// Created by DarsenOP on 2/8/25.
//

/* Basic Polymorphism */

// class Base
// {
// protected:
//     virtual int get_value() const = 0;
// public:
//     virtual ~Base() {}
//     int return_data() const { return this->get_value(); }
// };
//
// class Derived : public Base
// {
// private:
//     int get_value() const override
//     {
//         return 10;
//     }
// };

/* CRTP -> Static Polymorphism */

template <typename D>
class Base2
{
public:
    D& derived()
    {
        return static_cast<D&>(*this);
    }

    int return_data() { return derived().get_value(); }
};

class Derived2 : public Base2<Derived2>
{
public:
    int get_value() const { return 100; }
};