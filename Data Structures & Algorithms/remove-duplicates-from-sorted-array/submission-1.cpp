class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int k = 1; // Phần tử đầu tiên nums[0] luôn là duy nhất
        
        for (int i = 1; i < nums.size(); ++i) {
            // Nếu phần tử hiện tại khác với phần tử đứng trước nó
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Ghi đè vào vị trí k
                k++;               // Tăng k lên
            }
        }
        
        return k; // k chính là số lượng phần tử duy nhất
    }
};