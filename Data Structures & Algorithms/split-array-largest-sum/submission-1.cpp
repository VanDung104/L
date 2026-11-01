class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int limit) {
        int parts = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x <= limit) {
                sum += x;
            } else {
                // Bắt đầu đoạn mới chứa x.
                parts++;
                sum = x;

                if (parts > k) {
                    return false;
                }
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        for (int x : nums) {
            left = max(left, x);
            right += x;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {
                // mid đủ lớn, thử tìm giới hạn nhỏ hơn.
                right = mid;
            } else {
                // mid quá nhỏ, phải tăng giới hạn.
                left = mid + 1;
            }
        }

        return left;
    }
};