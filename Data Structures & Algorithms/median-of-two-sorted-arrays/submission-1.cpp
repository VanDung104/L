class Solution {
public:
    double findMedianSortedArrays(vector<int>& A,
                                  vector<int>& B) {
        // Đảm bảo A là mảng ngắn hơn.
        if (A.size() > B.size()) {
            return findMedianSortedArrays(B, A);
        }

        int m = A.size();
        int n = B.size();

        int half = (m + n + 1) / 2;

        int left = 0;
        int right = m;

        while (left <= right) {
            // Số phần tử lấy từ A vào bên trái.
            int x = left + (right - left) / 2;

            // Số phần tử lấy từ B vào bên trái.
            int y = half - x;

            int leftA = INT_MIN;
            int rightA = INT_MAX;
            int leftB = INT_MIN;
            int rightB = INT_MAX;

            if (x > 0) {
                leftA = A[x - 1];
            }

            if (x < m) {
                rightA = A[x];
            }

            if (y > 0) {
                leftB = B[y - 1];
            }

            if (y < n) {
                rightB = B[y];
            }

            if (leftA <= rightB && leftB <= rightA) {
                // Tổng lẻ: trung vị nằm cuối bên trái.
                if ((m + n) % 2 == 1) {
                    return max(leftA, leftB);
                }

                // Tổng chẵn: lấy hai phần tử giữa.
                return (max(leftA, leftB)
                        + min(rightA, rightB)) / 2.0;
            }

            if (leftA > rightB) {
                right = x - 1;
            } else {
                left = x + 1;
            }
        }

        // Với đầu vào hợp lệ, luôn tìm được cách chia.
        return 0.0;
    }
};