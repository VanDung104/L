class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        vector<ListNode*> nodes;

        ListNode* current = head;

        while (current != nullptr) {
            nodes.push_back(current);
            current = current->next;
        }

        int n = nodes.size();

        for (int i = n - 1; i > 0; i--) {
            nodes[i]->next = nodes[i - 1];
        }

        // The original head becomes the tail.
        nodes[0]->next = nullptr;

        // The original last node becomes the head.
        return nodes[n - 1];
    }
};