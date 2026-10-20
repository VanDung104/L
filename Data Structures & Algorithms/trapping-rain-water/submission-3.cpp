class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        
        vector<int> leftMax(n), rightMax(n);
        int total_water = 0;
        
        // Điền mảng leftMax từ trái sang phải
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        
        // Điền mảng rightMax từ phải sang trái
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        
        // Tính lượng nước tại mỗi cột
        for (int i = 0; i < n; ++i) {
            total_water += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return total_water;
    }
};