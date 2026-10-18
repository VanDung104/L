class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // cuối phần hợp lệ của nums1
        int j = n - 1;       // cuối nums2
        int k = m + n - 1;   // vị trí ghi (cuối nums1)

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        // Nếu j < 0: phần còn lại của nums1 đã đúng vị trí, không cần làm gì
    }
};