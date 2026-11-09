class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // 1. Insert each copy after its original.
        Node* original = head;
        while (original != nullptr) {
            Node* copy = new Node(original->val);
            copy->next = original->next;
            original->next = copy;
            original = copy->next;
        }

        // 2. Connect the random pointers while the lists are interleaved.
        original = head;
        while (original != nullptr) {
            Node* copy = original->next;

            if (original->random != nullptr) {
                copy->random = original->random->next;
            }

            original = copy->next;
        }

        // 3. Restore the original list and connect the copied list.
        Node* copyHead = head->next;
        original = head;

        while (original != nullptr) {
            Node* copy = original->next;
            Node* nextOriginal = copy->next;

            original->next = nextOriginal;
            if (nextOriginal != nullptr) {
                copy->next = nextOriginal->next;
            }

            original = nextOriginal;
        }

        return copyHead;
    }
};