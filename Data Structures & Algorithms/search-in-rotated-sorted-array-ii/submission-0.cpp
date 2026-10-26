#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            // Xử lý trường hợp các phần tử ở biên và giữa trùng nhau, không xác định được nửa nào sắp xếp
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // Kiểm tra xem nửa bên trái có được sắp xếp tăng dần không
            else if (nums[left] <= nums[mid]) {
                // Kiểm tra xem target có nằm trong khoảng của nửa trái không
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Thu hẹp sang nửa trái
                } else {
                    left = mid + 1;  // Chuyển sang nửa phải
                }
            }
            // Ngược lại, nửa bên phải bắt buộc được sắp xếp tăng dần
            else {
                // Kiểm tra xem target có nằm trong khoảng của nửa phải không
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Chuyển sang nửa phải
                } else {
                    right = mid - 1; // Thu hẹp sang nửa trái
                }
            }
        }
        
        return false; // Không tìm thấy
    }
};