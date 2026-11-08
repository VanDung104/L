class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // 1. Find the middle.
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two separate lists.
        ListNode* second = slow->next;
        slow->next = nullptr;

        // 2. Reverse the second half.
        ListNode* previous = nullptr;
        ListNode* current = second;

        while (current != nullptr) {
            ListNode* nextNode = current->next;

            current->next = previous;

            previous = current;
            current = nextNode;
        }

        second = previous;

        // 3. Merge the two halves alternately.
        ListNode* first = head;

        while (second != nullptr) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }
};