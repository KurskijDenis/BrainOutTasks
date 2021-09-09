#include <ReverseKElementsInList/ReverseKElementsInList.h>


namespace ReverseKElementsInList
{

ListNode::ListNode(const int new_value, ListNode* const new_next)
    : value(new_value)
    , next(new_next)
{}

ListNode::ListNode(ListNode&& new_node) noexcept
    : value(new_node.value)
    , next(new_node.next)
{
    new_node.value = 0;
    new_node.next = nullptr;
}

ListNode::~ListNode()
{
    if (next != nullptr)
    {
        delete next;
    }
}

ListNode* ReverseKElementsInList(ListNode* head, const size_t k) noexcept
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->next == nullptr)
    {
        return head;
    }

    size_t node_count = 0;
    {
        ListNode* it = head;
        while (it != nullptr) { ++node_count; it = it->next; }
    }
    if (k > node_count)
    {
        return head;
    }

    auto result = head;
    ListNode* prev_prev_node = nullptr;
    auto prev_node = head;
    for (size_t i = 0; i + k <= node_count; i += k)
    {
        auto it = prev_node->next;
        auto prev_saver = prev_node;

        for (size_t j = 1; j < k; ++j)
        {
            auto next_it = it->next;
            it->next = prev_node;
            prev_node = it;
            it = next_it;
        }
        if (prev_prev_node == nullptr)
        {
            result = prev_node;
        }
        else
        {
            prev_prev_node->next = prev_node;
        }
        prev_saver->next = it;

        prev_prev_node = prev_saver;
        prev_node = it;
    }
    return result;
}

} // namespace ReverseKElementsInList