class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Rút gọn k trong trường hợp k lớn hơn n
        if (k == 0) return;
        
        // Bước 1: Đảo ngược toàn bộ mảng
        reverse(nums.begin(), nums.end());
        
        // Bước 2: Đảo ngược k phần tử đầu tiên
        reverse(nums.begin(), nums.begin() + k);
        
        // Bước 3: Đảo ngược các phần tử còn lại từ k đến hết
        reverse(nums.begin() + k, nums.end());
    }
};