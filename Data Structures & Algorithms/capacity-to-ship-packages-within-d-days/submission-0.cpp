#include <bits/stdc++.h>
using namespace std;

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