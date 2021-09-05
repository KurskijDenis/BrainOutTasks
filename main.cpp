#include <MedianTwoSortedArrays/MedianTwoSortedArrays.h>

#include <exception>
#include <iostream>


int main(int /*argc*/, char** /*argv*/)
{
    try
    {

        std::cout << GetMedianTwoSortedArray({-1, 5}, {1, 8, 20});
    }
    catch(const std::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
    }
    return 0;
}