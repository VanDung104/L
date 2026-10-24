class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int ans = nums[0]; // Khởi tạo ban đầu

        while (left <= right) {
            // Nếu đoạn từ left tới right đã được sắp xếp tăng dần
            if (nums[left] <= nums[right]) {
                ans = min(ans, nums[left]);
                break;
            }

            int mid = left + (right - left) / 2;

            if (nums[mid] >= nums[left]) {
                // mid nằm ở đoạn trái (lớn) -> Không thể là min, thu hẹp sang phải
                left = mid + 1;
            } else {
                // mid nằm ở đoạn phải (nhỏ) -> nums[mid] là ứng viên min, cập nhật ngay!
                ans = min(ans, nums[mid]);
                right = mid - 1; 
            }
        }
        return ans;
    }
};