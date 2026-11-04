class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            // 1. Save the next node.
            ListNode* nextNode = current->next;

            // 2. Reverse the current connection.
            current->next = previous;

            // 3. Move forward.
            previous = current;
            current = nextNode;
        }

        return previous;
    }
};