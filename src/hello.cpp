#include "hello.hpp"

void hello(void)
{
    std::cout << "Hello, world!" << std::endl;
}

int factorial(const  unsigned int &n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

// This function gets caught by cppcheck: uncomment to see

// int faulty_function(int* arr)
// {
//     int a = arr[0];
//     return 0;
// }