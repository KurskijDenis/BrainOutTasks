#include <SortVectorOfLists/SortVectorOfLists.h>

#include <gtest/gtest.h>

#include <vector>


TEST(SortVectorOfLists, EmptyVector)
{
    EXPECT_TRUE(MergeLists({}).empty());
}

TEST(SortVectorOfLists, EmptyListsInVector)
{
    EXPECT_TRUE(MergeLists({{}, {}, {}}).empty());
}

TEST(SortVectorOfLists, OneListInVector)
{
    EXPECT_EQ(MergeLists({{1, 2, 3, 4}}), std::list<int>({1, 2, 3, 4}));
}

TEST(SortVectorOfLists, TwoSequentalListsInVector)
{
    EXPECT_EQ(MergeLists({{1, 2, 3, 4}, {5, 6, 7, 9}}), std::list<int>({1, 2, 3, 4, 5, 6, 7, 9}));
    EXPECT_EQ(MergeLists({{5, 6, 7, 9}, {1, 2, 3, 4}}), std::list<int>({1, 2, 3, 4, 5, 6, 7, 9}));
    EXPECT_EQ(MergeLists({{1, 2, 3, 4}, {}}), std::list<int>({1, 2, 3, 4}));
    EXPECT_EQ(MergeLists({{}, {1, 2, 3, 4}}), std::list<int>({1, 2, 3, 4}));
}


TEST(SortVectorOfLists, TwoRandomListsInVector)
{
    EXPECT_EQ(MergeLists({{1, 10, 20, 30}, {5, 15, 16, 21}}), std::list<int>({1, 5, 10, 15, 16, 20, 21, 30}));
    EXPECT_EQ(MergeLists({{5, 15, 16, 21}, {1, 10, 20, 30}}), std::list<int>({1, 5, 10, 15, 16, 20, 21, 30}));
}

TEST(SortVectorOfLists, ThreeSequentalListsInVector)
{
    EXPECT_EQ(MergeLists({{1, 2, 3, 4}, {5, 6, 7, 9}, {-90}}), std::list<int>({-90, 1, 2, 3, 4, 5, 6, 7, 9}));
    EXPECT_EQ(MergeLists({{5, 6, 7, 9}, {-90}, {1, 2, 3, 4}}), std::list<int>({-90, 1, 2, 3, 4, 5, 6, 7, 9}));
    EXPECT_EQ(MergeLists({{}, {-90}, {1, 2, 3, 4}}), std::list<int>({-90, 1, 2, 3, 4}));
    EXPECT_EQ(MergeLists({{}, {-90}, {}}), std::list<int>({-90}));
}

TEST(SortVectorOfLists, ThreeRandomListsInVector)
{
    EXPECT_EQ(MergeLists({{1, 10, 20, 30}, {5, 15, 16, 21}, {3, 120}}), std::list<int>({1, 3, 5, 10, 15, 16, 20, 21, 30, 120}));
    EXPECT_EQ(MergeLists({{5, 15, 16, 21}, {3, 120}, {1, 10, 20, 30}}), std::list<int>({1, 3, 5, 10, 15, 16, 20, 21, 30, 120}));
}