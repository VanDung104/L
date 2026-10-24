#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();    // Số hàng
        int n = matrix[0].size(); // Số cột
        
        int left = 0;
        int right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Quy đổi chỉ số mid (1D) sang tọa độ (row, col) trên 2D
            int row = mid / n;
            int col = mid % n;
            
            int val = matrix[row][col];
            
            if (val == target) {
                return true; // Tìm thấy target
            } 
            else if (val < target) {
                left = mid + 1; // Thu hẹp sang nửa bên phải
            } 
            else {
                right = mid - 1; // Thu hẹp sang nửa bên trái
            }
        }
        
        return false; // Không tìm thấy
    }
};