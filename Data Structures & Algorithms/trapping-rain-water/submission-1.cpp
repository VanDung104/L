class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int total_water = 0;
        
        while (left <= right) {
            if (height[left] < height[right]) {
                // Nếu chiều cao bên trái nhỏ hơn bên phải
                if (height[left] >= leftMax) {
                    leftMax = height[left]; // Cập nhật bức tường chắn cao nhất bên trái
                } else {
                    total_water += leftMax - height[left]; // Nước đọng lại
                }
                left++;
            } else {
                // Nếu chiều cao bên phải nhỏ hơn hoặc bằng bên trái
                if (height[right] >= rightMax) {
                    rightMax = height[right]; // Cập nhật bức tường chắn cao nhất bên phải
                } else {
                    total_water += rightMax - height[right]; // Nước đọng lại
                }
                right--;
            }
        }
        
        return total_water;
    }
};