#include <SortVectorOfLists/SortVectorOfLists.h>

namespace
{

std::list<int> MergeLists(const std::list<int>& list1, const std::list<int>& list2)
{
    if (list1.empty())
    {
        return list2;
    }
    if (list2.empty())
    {
        return list1;
    }
    auto it1 = list1.begin();
    auto it2 = list2.begin();
    std::list<int> result;
    {
        auto it = it2;
        if (*it1 < *it2)
        { 
            it = it1;
            ++it1;
        }
        else
        {
            ++it2;  
        }
        result.push_back(*it);
    }

    while (it1 != list1.cend() && it2 != list2.cend())
    {
        auto it = it2;
        if (*it1 < *it2)
        {
            it = it1;
            ++it1;
        }
        else
        {
            ++it2;
        }
        result.push_back(*it);
    }
    if (it1 != list1.cend())
    {
        result.insert(result.cend(), it1, list1.cend());
    }
    if (it2 != list2.cend())
    {
        result.insert(result.cend(), it2, list2.cend());
    }
    return result;
}

std::list<int> MergeLists(const std::vector<std::list<int>>::const_iterator it1, const std::vector<std::list<int>>::const_iterator it2)
{
    if (it1 == it2)
    {
        return *it1;
    }
    if (std::next(it1) == it2)
    {
        return MergeLists(*it1, *it2);
    }
    const auto next_it = std::next(it1, std::distance(it1, it2) / 2);
    return MergeLists(MergeLists(it1, next_it), MergeLists(std::next(next_it), it2));
}

}

std::list<int> MergeLists(const std::vector<std::list<int>>& lists)
{
    if (lists.empty())
    {
        return {};
    }

    return MergeLists(lists.cbegin(), std::prev(lists.cend()));
}