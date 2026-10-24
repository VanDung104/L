#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= nums[right]) {
                // mid nằm ở đoạn trái, min nằm bên phải mid
                left = mid + 1;
            } else {
                // mid nằm ở đoạn phải, min có thể là mid hoặc bên trái mid
                right = mid;
            }
        }

        // Khi left == right, ta đã dừng lại đúng điểm gãy (phần tử nhỏ nhất)
        return nums[left];
    }
};