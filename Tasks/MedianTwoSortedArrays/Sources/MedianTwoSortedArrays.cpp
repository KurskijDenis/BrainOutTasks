#include <MedianTwoSortedArrays/MedianTwoSortedArrays.h>

#include <iostream>

float GetMedianTwoSortedArray(const std::vector<int>& array1, const std::vector<int>& array2)
{
    const auto element_count = array1.size() + array2.size();
    if (element_count == 0)
    {
        throw std::runtime_error("Empty arrays");
    }
    else if (element_count == 1)
    {
        return array1.empty() ? array2.front() : array1.front();
    }

    const auto median_index = element_count / 2;
    const auto is_even = element_count % 2 == 0;
    
    size_t i = 0, j = 0;
    int prev_value = 0;
    int min_value = 0;
    for (; i < array1.size() && j < array2.size();)
    {
        prev_value = min_value;
        min_value = array1[i];
        if (min_value > array2[j])
        {
            min_value = array2[j];
            ++j;
        }
        else
        {
            ++i;
        }
        if (i + j == median_index + 1)
        {
            return is_even ? (min_value + prev_value) / 2.0f : min_value;
        }
    }

    for (; i < array1.size(); ++i)
    {
        prev_value = min_value;
        min_value = array1[i];
        if (i + j == median_index)
        {
            return is_even ? (min_value + prev_value) / 2.0f : min_value;
        }
    }
    for (; j < array2.size(); ++j)
    {
        prev_value = min_value;
        min_value = array2[j];
        if (i + j == median_index)
        {
            return is_even ? (min_value + prev_value) / 2.0f : min_value;
        }
    }
    throw std::runtime_error("Unreachable code block");
    return 0;
}