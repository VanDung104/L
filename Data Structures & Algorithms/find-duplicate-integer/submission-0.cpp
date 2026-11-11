class Solution {
public:
    int findDuplicate(const std::vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        // Giai đoạn 1: Gặp nhau ở đâu đó bên trong chu trình.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Giai đoạn 2: Tìm điểm vào chu trình.
        int fromStart = 0;

        while (fromStart != slow) {
            fromStart = nums[fromStart];
            slow = nums[slow];
        }

        return fromStart;
    }
};