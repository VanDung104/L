class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = head;
        ListNode* slow = &dummy;

        // Move fast n steps ahead.
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move together until fast reaches the end.
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow is immediately before the target.
        ListNode* removed = slow->next;
        slow->next = removed->next;
        delete removed;

        return dummy.next;
    }
};