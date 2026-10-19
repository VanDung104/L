class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;
        
        // Bước 1: Sắp xếp mảng tăng dần
        sort(nums.begin(), nums.end());
        
        // Bước 2: Cố định phần tử thứ nhất (i)
        for (int i = 0; i < n - 3; ++i) {
            // Bỏ qua các giá trị trùng lặp của i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Bước 3: Cố định phần tử thứ hai (j)
            for (int j = i + 1; j < n - 2; ++j) {
                // Bỏ qua các giá trị trùng lặp của j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                // Bước 4: Dùng Two Pointers cho 2 phần tử còn lại
                while (left < right) {
                    // Dùng long long để tránh tràn số khi cộng 4 số lớn
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
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
        }
        
        return result;
    }
};