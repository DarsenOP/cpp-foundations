//
// Created by DarsenOP on 2/2/25.
//

/* Pointers */

#include <iostream>

int main()
{
    // Declaration
    int* p_number {}; // Can only store address of a variable of type int
    double* p_fractional_number{}; // Can only store address of a variable of type double

    // Explicitly initialize to nullptr
    int* p_number1 {nullptr};
    double* p_fractional_number1 {nullptr};

    // All pointers have the same size that depends on architecture
    // Better to separate declarations on different lines to avoid confusion

    // Assigning data to pointer variables
    int int_var {42};
    int* p_int {&int_var}; // The address of int_var

    std::cout << int_var << std::endl;
    std::cout << p_int << std::endl;

    // Or using dereferencing to get the value at the memory the pointer points to
    std::cout << *p_int << std::endl;

    // You can also change the address
    int int_var1 {32};
    p_int = &int_var1;

    std::cout << int_var1 << std::endl;
    std::cout << p_int << std::endl;

    // Can only contain the type for which they were declared
    int* p_error{};
    double double_var_error{33};

    // p_error = &double_var_error; // Error

    // Initialize with string literal
    char* p_message {"Hello World!"}; // This is a special case

    std::cout << p_message << std::endl; // This time it is the message itself, not the address
    std::cout << *p_message << std::endl; // Still the pointer contains the address of the first element

    // Automatically it is const char*, so we cannot make any changes
    // *p_message = "B";
    // std::cout << p_message << std::endl;

    // Memory map
    // Text (The code itself), Data (For example string literals), Heap (For dynamic allocation (additional storage)),
    // Stack (Default storage for local variables, functions, classes, ...),
    // System (All the information needed for the system)

    // BAD THINGS
    // int *p_number2; // Uninitialized pointer, that contains junk address, so it could be anything
    // *p_number2 = 42; // Writing into junk address which very bad
    //
    // int *p_number3 {}; // Initialize to nullptr, pointer that points to nothing
    // *p_number3 = 42; // Writing into nullptr is also pretty bad that will most probably cause a crash


    // Stack vs Heap
    // Stack: 1) Memory is finite, 2) The developer isn't in full control of the memory lifetime,
    //        3) Lifetime is controlled by the scope mechanism
    // Heap: 1) Memory is again finite, 2) The developer is in full control at when memory is allocated and when it
    //       is released, 3) Lifetime is controlled explicitly through new and delete operations

    // Lifetime through scope mechanism
    {
        int local_scope_var {33}; // The memory gets released after the scope
    }

    // Allocate dynamic memory with new
    int* p_number4 {};
    p_number4 = new int; // Here we allocate memory that becomes ours and no other program can use it till we release
                         // it, the size of the memory will be as much as needed for the `int`

    *p_number4 = 42; // Writing into dynamically allocated memory

    {
        int* local_ptr_var = new int; // Because heap is not controlled by scope,
                                      // then the memory will still exist, even though the variable that holds it
                                      // is going to get destroyed after the scope, and we will have a memory leak
        delete local_ptr_var;
        local_ptr_var = nullptr;
    }
    // Proper way to release and reset memory
    delete p_number4; // Release memory so the other programs can use it
    p_number4 = nullptr; // Even though we still hold the memory in the pointer, we do not have access to it, and we can
                         // modify another programs memory, so we should reset the memory to nullptr after delete

    // Double deletion is bad and can cause a crash!!!
    // Dangling pointer: 1) Uninitialized pointers, 2) Deleted pointer, 3) Multiple pointers pointing to the same memory
    // 1)
    // int* p_number5; // BAD, initialize with nullptr
    // delete p_number5;
    // p_number5 = nullptr;
    // 2)
    // std::cout << p_number5 << std::endl; // BAD, should reset to nullptr after delete
    // 3)
    int* p_number6 {new int {35}};
    // int* p_number7 {p_number6};
    //
    delete p_number6;
    p_number6 = nullptr;
    // std::cout << p_number7 << std::endl; // BAD because the memory it was pointing-the same as pointer 6- was deleted
    // delete p_number7;
    // p_number7 = nullptr;

    // Sometimes the new operator (in some rare cases) can fail which will cause an error in future and even may cause
    // a crash, which is very bad. To tackle this problem we can use 1) exception mechanism, 2) std::notrhow
    // 1), 2)
    for (size_t i{}; i < 1000000000; i++) {
        int* lots_of_ints {new(std::nothrow) int[1000000000]};
        if (lots_of_ints != nullptr)
            std::cout << "SUCCESS!";
        else {
            std::cout << "FAILURE!";
            break;
        }
    }

    // Null pointer check safety, deleting a null pointer is okay
    // Memory leak: when we loose access to memory that is dynamically allocated
    // 1) Reassignment of stack address to active dynamic pointer ---> SOLUTION: delete and reset before assignment
    // 2) Double allocation
    // 3) Pointer in local scope

    // Dynamically allocated arrays
    // First 5 elements initialized the other initialized to 0
    double* temperatures {new(std::nothrow) double[50] {10.0, 20.0, 30.0, 40.0, 50.0}};
    if (temperatures) {
        for (size_t i{}; i < 50; i++) {
            std::cout << temperatures[i] << std::endl;
        }
    } else {
        std::cout << "Allocation Failed!" << std::endl;
    }

    // Releaseing memory of a dynamically allocated array
    delete[] temperatures;
    temperatures = nullptr;

    // These arrays do not support range based for loop and std::size

    return 0;
}