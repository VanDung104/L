class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int currentSum = numbers[left] + numbers[right];
            
            if (currentSum == target) {
                return {left + 1, right + 1}; // Trả về dạng 1-indexed
            } else if (currentSum > target) {
                right--; // Tổng lớn hơn target -> giảm số lớn ở bên phải
            } else {
                left++;  // Tổng nhỏ hơn target -> tăng số nhỏ ở bên trái
            }
        }
        
        return {}; // Đề bài đảm bảo luôn có nghiệm nên dòng này thực tế không chạy tới
    }
};