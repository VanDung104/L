class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* beforeLeft = &dummy;
        for (int position = 1; position < left; ++position) {
            beforeLeft = beforeLeft->next;
        }

        ListNode* segmentTail = beforeLeft->next;
        ListNode* current = segmentTail;
        ListNode* previous = nullptr;

        for (int position = left; position <= right; ++position) {
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        segmentTail->next = current;
        beforeLeft->next = previous;

        return dummy.next;
    }
};