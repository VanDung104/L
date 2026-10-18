class Solution {
    bool isPalin(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                // Thử bỏ s[l] hoặc bỏ s[r]
                return isPalin(s, l + 1, r) || isPalin(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true; // đã là palindrome, không cần xoá
    }
};