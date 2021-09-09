#include <exception>
#include <iostream>
#include <vector>


int main(int /*argc*/, char** /*argv*/)
{
    try
    {

    }
    catch(const std::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
    }
    return 0;
}