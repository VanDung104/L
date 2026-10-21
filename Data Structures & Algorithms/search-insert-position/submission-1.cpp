#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // Tránh tràn số
            
            if (nums[mid] == target) {
                return mid; // Tìm thấy chính xác
            } 
            else if (nums[mid] < target) {
                left = mid + 1; // Target lớn hơn, tìm ở nửa bên phải
            } 
            else {
                right = mid - 1; // Target nhỏ hơn, tìm ở nửa bên trái
            }
        }
        
        // Khi vòng lặp kết thúc mà không thấy, `left` chính là vị trí chèn chuẩn xác
        return left;
    }
};