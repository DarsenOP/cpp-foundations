//
// Created by DarsenOP on 2/8/25.
//

#include "Value.h"
#include "Ptr2.h"

int main()
{
    Ptr2 f;
    Ptr2 f2;

    std::cout << "Value in f: " << f.get() << std::endl;
    std::cout << "Value in f2: " << f2.get() << std::endl;

    f = std::move(f2);

    std::cout << "Value in f: " << f.get() << std::endl;
    std::cout << "Value in f2: " << f2.get() << std::endl;

    return 0;
}