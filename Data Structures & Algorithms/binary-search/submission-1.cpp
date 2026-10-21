#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // Tránh tràn số (overflow) khi left và right có giá trị lớn
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid; // Tìm thấy, trả về chỉ số
            } 
            else if (nums[mid] < target) {
                left = mid + 1; // Target ở nửa bên phải
            } 
            else {
                right = mid - 1; // Target ở nửa bên trái
            }
        }
        
        return -1; // Không tìm thấy
    }
};