#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        // Xử lý trường hợp đặc biệt khi x = 0 hoặc x = 1
        if (x < 2) {
            return x;
        }
        
        int left = 1;
        int right = x / 2; // Căn bậc hai của x (với x >= 2) không bao giờ vượt quá x / 2
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Ép kiểu (long long) để tránh tràn số (overflow) khi mid * mid quá lớn
            long long square = (long long)mid * mid;
            
            if (square == x) {
                return mid;
            } 
            else if (square < x) {
                ans = mid;       // Lưu lại kết quả tạm thời
                left = mid + 1;  // Thử tìm giá trị lớn hơn ở bên phải
            } 
            else {
                right = mid - 1; // Thu hẹp khoảng tìm kiếm sang bên trái
            }
        }
        
        return ans; // Trả về kết quả đã được làm tròn xuống
    }
};