#include <ReverseKElementsInList/ReverseKElementsInList.h>

#include <gtest/gtest.h>
#include <vector>


TEST(ReverseKElementsInList, NullList)
{
    EXPECT_EQ(ReverseKElementsInList::ReverseKElementsInList(nullptr, 1), nullptr);
}

TEST(ReverseKElementsInList, OneElementList)
{
    const std::vector<int> expected_values{2};
    const auto head = new ReverseKElementsInList::ListNode(expected_values.front(), nullptr);
    const auto new_head = ReverseKElementsInList::ReverseKElementsInList(head, 1);

    auto it = new_head;
    for (const auto v : expected_values)
    {
        ASSERT_NE(it, nullptr);
        EXPECT_EQ(it->value, v);
        it = it->next;
    }
    ASSERT_EQ(it, nullptr);
    delete new_head;
}


TEST(ReverseKElementsInList, NotReverseList)
{
    const std::vector<int> expected_values{1, 2, 3, 4, 5, 6, 7, 8};

    const auto head = new ReverseKElementsInList::ListNode(expected_values.front(), nullptr);
    auto tail_it = head;
    for (auto it = std::next(expected_values.cbegin()); it != expected_values.cend(); ++it)
    {
        tail_it->next = new ReverseKElementsInList::ListNode(*it, nullptr);
        tail_it = tail_it->next;
    }

    const auto new_head = ReverseKElementsInList::ReverseKElementsInList(head, 1);

    auto it = new_head;
    for (const auto v : expected_values)
    {
        ASSERT_NE(it, nullptr);
        EXPECT_EQ(it->value, v);
        it = it->next;
    }
    ASSERT_EQ(it, nullptr);
    delete new_head;
}

TEST(ReverseKElementsInList, ReverseAllList)
{
    const std::vector<int> list_values{1, 2, 3, 4, 5, 6, 7, 8};

    const auto head = new ReverseKElementsInList::ListNode(list_values.front(), nullptr);
    auto tail_it = head;
    for (auto it = std::next(list_values.cbegin()); it != list_values.cend(); ++it)
    {
        tail_it->next = new ReverseKElementsInList::ListNode(*it, nullptr);
        tail_it = tail_it->next;
    }

    const auto new_head = ReverseKElementsInList::ReverseKElementsInList(head, 8);

    const std::vector<int> expected_values{8, 7, 6, 5, 4, 3, 2, 1};
    auto it = new_head;
    for (const auto v : expected_values)
    {
        ASSERT_NE(it, nullptr);
        EXPECT_EQ(it->value, v);
        it = it->next;
    }
    ASSERT_EQ(it, nullptr);
    delete new_head;
}

TEST(ReverseKElementsInList, ReverseListWithRemainder)
{
    const std::vector<int> list_values{1, 2, 3, 4, 5, 6, 7, 8};

    const auto head = new ReverseKElementsInList::ListNode(list_values.front(), nullptr);
    auto tail_it = head;
    for (auto it = std::next(list_values.cbegin()); it != list_values.cend(); ++it)
    {
        tail_it->next = new ReverseKElementsInList::ListNode(*it, nullptr);
        tail_it = tail_it->next;
    }

    const auto new_head = ReverseKElementsInList::ReverseKElementsInList(head, 3);

    const std::vector<int> expected_values{3, 2, 1, 6, 5, 4, 7, 8 };
    auto it = new_head;
    for (const auto v : expected_values)
    {
        ASSERT_NE(it, nullptr);
        EXPECT_EQ(it->value, v);
        it = it->next;
    }
    ASSERT_EQ(it, nullptr);
    delete new_head;
}

TEST(ReverseKElementsInList, ReverseListWithoutRemainder1)
{
    const std::vector<int> list_values{1, 2, 3, 4, 5, 6, 7, 8};

    const auto head = new ReverseKElementsInList::ListNode(list_values.front(), nullptr);
    auto tail_it = head;
    for (auto it = std::next(list_values.cbegin()); it != list_values.cend(); ++it)
    {
        tail_it->next = new ReverseKElementsInList::ListNode(*it, nullptr);
        tail_it = tail_it->next;
    }

    const auto new_head = ReverseKElementsInList::ReverseKElementsInList(head, 2);

    const std::vector<int> expected_values{2, 1, 4, 3, 6, 5, 8, 7 };
    auto it = new_head;
    for (const auto v : expected_values)
    {
        ASSERT_NE(it, nullptr);
        EXPECT_EQ(it->value, v);
        it = it->next;
    }
    ASSERT_EQ(it, nullptr);
    delete new_head;
}

TEST(ReverseKElementsInList, ReverseListWithoutRemainder2)
{
    const std::vector<int> list_values{1, 2, 3, 4, 5, 6, 7, 8};

    const auto head = new ReverseKElementsInList::ListNode(list_values.front(), nullptr);
    auto tail_it = head;
    for (auto it = std::next(list_values.cbegin()); it != list_values.cend(); ++it)
    {
        tail_it->next = new ReverseKElementsInList::ListNode(*it, nullptr);
        tail_it = tail_it->next;
    }

    const auto new_head = ReverseKElementsInList::ReverseKElementsInList(head, 4);

    const std::vector<int> expected_values{4, 3, 2, 1, 8, 7, 6, 5 };
    auto it = new_head;
    for (const auto v : expected_values)
    {
        ASSERT_NE(it, nullptr);
        EXPECT_EQ(it->value, v);
        it = it->next;
    }
    ASSERT_EQ(it, nullptr);
    delete new_head;
}