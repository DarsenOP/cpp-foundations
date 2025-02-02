//
// Created by DarsenOP on 2/2/25.
//

/* Arrays */

#include <iostream>

int main()
{
    // Declaring arrays
    int scores[10];

    // Mannual display of all items
    std::cout << scores[0] << std::endl;
    std::cout << scores[1] << std::endl;
    //...
    std::cout << scores[9] << std::endl;

    // We can not specify the size, and do the display with loops
    int other_scores[] = {10, 12, 15, 19, 24, 30};

    // Array size using std::size
    std::cout << "The size of other scores: " << std::size(other_scores) << std::endl;
    // Array size using sizeof
    size_t count {sizeof(other_scores) / sizeof(other_scores[0])};

    for (size_t i = 0; i < count; i++) {
        std::cout << other_scores[i] << std::endl;
    }

    std::cout << "Using plane old range based for loop" << std::endl;
    // Looping though an array
    for (auto score : other_scores) {
        std::cout << score << std::endl;
    }

    // Array of characters (it is a bit different)
    char message[5] = {'H', 'e', 'l', 'l', 'o'}; // This is not a cstring

    std::cout << message << std::endl; // Without proper null termination
    for (auto character : message) {
        std::cout << character;
    }
    std::cout << std::endl;
    std::cout << "size: " << sizeof(message) << std::endl;

    // Direct print out
    char message2[6] {'H', 'e', 'l', 'l', 'o', '\0'}; // With proper null termination, this is a cstring
    std::cout << message2 << std::endl;
    std::cout << std::size(message2) << std::endl;

    // Literal cstrings
    std::cout << std::endl;
    char message4[] {"Hello"}; // An implicit '\0' character is appended to the end of the string, making it a cstring
    std::cout << message4 << std::endl;

    // Can even have spaces between characters
    std::cout << std::endl;
    char message5[] {"Hello World!"};
    std::cout << message5 << std::endl;

    // Array bounds
    int number_array[] {1,2,3,4,5,6,7,8,9,0};

    std::cout << number_array[12] << std::endl; // Compiler allows, but this memory is not owned by number_array
    number_array[12] = 1000;                    // You can even modify another program's memory
    std::cout << number_array[12] << std::endl;

    return 0;
}