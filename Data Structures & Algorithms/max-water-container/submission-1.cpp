class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            // Tính diện tích nước chứa được giữa hai cột left và right
            int width = right - left;
            int h = min(height[left], height[right]);
            int current_area = width * h;
            
            // Cập nhật diện tích lớn nhất
            max_area = max(max_area, current_area);
            
            // Dịch chuyển con trỏ có chiều cao nhỏ hơn vào trong
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};