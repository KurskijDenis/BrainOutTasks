#include <cstdlib>


namespace ReverseKElementsInList
{

struct ListNode
{
    ListNode(const int new_value, ListNode* const new_next);
    ListNode(const ListNode& new_node) = delete;
    ListNode& operator=(const ListNode& new_node) = delete;
    ListNode(ListNode&& new_node) noexcept;

    ~ListNode();

    int value = 0;
    ListNode* next = nullptr;
};

ListNode* ReverseKElementsInList(ListNode* head, const size_t k) noexcept;

} // namespace ReverseKElementsInList