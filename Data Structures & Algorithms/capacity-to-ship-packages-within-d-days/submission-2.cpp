#include <bits/stdc++.h>
using namespace std;

// while (left < right) và right = mid: Gọn gàng hơn cho các bài toán tìm cận dưới (lower bound) như thế này, không cần biến ans.

// while (left <= right) và right = mid - 1: Phải dùng khi bạn tìm kiếm một giá trị chính xác hoặc cần một biến ans riêng biệt.
class Solution {
private:
    bool canShip(const vector<int>& weights, int days, int capacity) {
        int days_needed = 1, current_weight = 0;
        for (int w : weights) {
            if (current_weight + w > capacity) {
                days_needed++;
                current_weight = w;
            } else {
                current_weight += w;
            }
        }
        return days_needed <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};