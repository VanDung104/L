class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Bước 1: Sắp xếp mảng tăng dần
        sort(nums.begin(), nums.end());
        
        // Bước 2: Duyệt từng phần tử làm mốc
        for (int i = 0; i < n - 2; ++i) {
            // Nếu phần tử mốc đã > 0, tổng 3 số dương không thể bằng 0 -> Dừng
            if (nums[i] > 0) break;
            
            // Bỏ qua các giá trị trùng lặp của mốc i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            
            // Bước 3: Dùng Two Pointers cho phần bên phải
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Bỏ qua các giá trị trùng lặp của left và right
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } 
                else if (sum < target) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        
        return result;
    }
};