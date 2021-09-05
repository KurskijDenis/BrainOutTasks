#include <MedianTwoSortedArrays/MedianTwoSortedArrays.h>

#include <gtest/gtest.h>

#include <vector>


TEST(MedianTwoSortedArrays, EmptyArrays)
{
    EXPECT_THROW(GetMedianTwoSortedArray({}, {}), std::runtime_error);
}

TEST(MedianTwoSortedArrays, Array1WithOneValue_Array2Empty)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({1}, {}), 1.0f);
}

TEST(MedianTwoSortedArrays, Array2WithOneValue_Array1Empty)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({}, {5}), 5.0f);
}

TEST(MedianTwoSortedArrays, Array2OneValue_Array1WithOneValue)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({3}, {9}), 6.0f);
}

TEST(MedianTwoSortedArrays, Array1WithTwoValues_Array2Empty)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({-9, 5}, {}), -2.0f);
}

TEST(MedianTwoSortedArrays, Array1WithThreeValues_Array2Empty)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({-9, 5, 8}, {}), 5.0f);
}

TEST(MedianTwoSortedArrays, Array2WithTwoValues_Array1Empty)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({}, {8, 12}), 10.0f);
}

TEST(MedianTwoSortedArrays, Array2WithThreeValues_Array1Empty)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({}, {1, 8, 23}), 8.0f);
}

TEST(MedianTwoSortedArrays, OddValueCount)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({-1, 5, 23}, {1, 8, 20}), 6.5f);
}

TEST(MedianTwoSortedArrays, EvenValueCount)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({-1, 5}, {1, 8, 20}), 5.0f);
}

TEST(MedianTwoSortedArrays, MedianFormOneValueArray)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({5}, {1, 4, 8, 20}), 5.0f);
}

TEST(MedianTwoSortedArrays, MedianBetweenArrays)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({1, 5}, {6, 7}), 5.5f);
}

TEST(MedianTwoSortedArrays, EscapeOneArray)
{
    EXPECT_FLOAT_EQ(GetMedianTwoSortedArray({8, 90, 100}, {6, 7}), 8.0f);
}