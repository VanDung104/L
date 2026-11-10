#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> copies;
        copies[nullptr] = nullptr;

        // Tạo một bản sao cho mỗi node gốc.
        Node* original = head;
        while (original != nullptr) {
            copies[original] = new Node(original->val);
            original = original->next;
        }

        // Kết nối mỗi bản sao với các node đã sao chép tương ứng.
        original = head;
        while (original != nullptr) {
            Node* copy = copies[original];
            copy->next = copies[original->next];
            copy->random = copies[original->random];
            original = original->next;
        }

        return copies[head];
    }
};