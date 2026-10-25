#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Nếu tìm thấy target, trả về vị trí mid ngay lập tức
            if (nums[mid] == target) return mid;

            // Bước 1: Kiểm tra xem nửa trái có đang được sắp xếp bình thường không
            if (nums[left] <= nums[mid]) {
                // Kiểm tra xem target có nằm trong khoảng của nửa trái không
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Thu hẹp về trái
                } else {
                    left = mid + 1;  // Đi tìm ở phải
                }
            } 
            // Bước 2: Nếu nửa trái không sắp xếp chuẩn, chắc chắn nửa phải sắp xếp chuẩn
            else {
                // Kiểm tra xem target có nằm trong khoảng của nửa phải không
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Thu hẹp về phải
                } else {
                    right = mid - 1; // Đi tìm ở trái
                }
            }
        }

        // Không tìm thấy target trong mảng
        return -1;
    }
};