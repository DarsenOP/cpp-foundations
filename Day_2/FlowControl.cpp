//
// Created by DarsenOP on 2/2/25.
//

/* Flow Control */

#include <iostream>

const int PEN {10};
const int MARKER {20};
const int ERASER {30};

int main()
{
    // if, else if, else
    bool is_red {false};
    int a {5};
    int b {6};

    if (a > b) {
        std::cout << a << " is greater than b" << std::endl;
    } else if (a * 2 == b) {
        std::cout << a << " is less than or equal b" << std::endl;
    } else if (is_red) {
        std::cout << "The color is red!\n";
    } else {
        std::cout << "Something else!\n";
    }

    // switch
    int tool{PEN};

    switch (tool) {
        case PEN:
        {
            std::cout << PEN;
            break;
        }
        case MARKER:
        {
            std::cout << MARKER;
            break;
        }
        case ERASER:
        {
            std::cout << ERASER;
            break;
        }
        default:
        {
            std::cout << "Something else!";
            break;
        }
    }

    // Ternary operator : result = (condition) ? option1 : option2
    int max_number = (a > b) ? a : b; // Types of the output should be either the same or convertable
    std::cout << "\nmax(" << a << ", " << b << "): " << max_number << std::endl;

    return 0;
}