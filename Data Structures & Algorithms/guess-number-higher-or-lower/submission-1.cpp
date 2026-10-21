/** 
 * Forward declaration of guess API.
 * @param num   your guess
 * @return 	-1 if num is higher than the picked number
 *			 1 if num is lower than the picked number
 *			 otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while (left <= right) {
            // Tránh tràn số khi n rất lớn
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            
            if (res == 0) {
                return mid; // Đoán đúng
            } 
            else if (res < 0) { // res == -1: num > pick
                right = mid - 1; // Thu hẹp sang nửa bên trái
            } 
            else { // res == 1: num < pick
                left = mid + 1; // Mở rộng sang nửa bên phải
            }
        }
        
        return -1; // Bài toán luôn có đáp án nên dòng này thực tế không chạy tới
    }
};