#include <vector>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        
        // Tìm giá trị lớn nhất trong piles để làm chặn trên (right)
        for (int p : piles) {
            right = std::max(right, p);
        }
        
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            long long hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid; // Công thức tính ceil(p / mid) tránh dùng số thực
            }
            
            if (hours <= h) {
                ans = mid;         // Lưu lại kết quả hợp lệ
                right = mid - 1;   // Thử tìm k nhỏ hơn ở nửa bên trái
            } else {
                left = mid + 1;    // Quá chậm, tăng tốc độ k lên ở nửa bên phải
            }
        }
        
        return ans;
    }
};