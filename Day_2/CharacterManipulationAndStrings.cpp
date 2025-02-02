//
// Created by DarsenOP on 2/2/25.
//

/* Character Manipulation and Strings */

#include <iostream>
#include <cctype>
#include <string>

int main()
{
    // Basic(Better) facilities to handle text data in C++
    // Character manipulation with <cctype>
    // std::isalnum, std::isalpha, std::islower, std::isupper, std::isdigit, std::isspace, std::isblank,
    // std::tolower, std::toupper

    // Cstring manipulation
    // std::strcopy, std::strncopy, std::strcat, std::strncat, std::strlen, std::strcmp, std::strncmp,
    // std::strchr, std::strrchr

    // Better way to manipulate strings using std::string
    std::string s {"Hello, World!"}; // Initialize
    std::string s1 {"Arsen", 3}; // Take first 3 characters
    std::cout << s << "\n" << s1 << std::endl;

    std::string e7(7, 'e'); // 7 copies of 'e'm should be used functional initialization
    std::cout << e7 << std::endl;

    std::string s3 {s, 3, 5}; // Number of characters taken is 7 starting from 3
    std::cout << s3 << std::endl;

    // Cstring VS std::string
    // Better memory management with std::string when reassigning, the memory is being recovered where as in cstring
    // wasted

    return 0;
}