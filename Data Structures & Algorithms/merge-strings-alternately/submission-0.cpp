class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int n = min(word1.size(), word2.size());
        for (int i = 0; i < n; i++) {
            res = res + word1[i];   // tạo chuỗi mới mỗi lần
            res = res + word2[i];
        }
        res = res + word1.substr(n) + word2.substr(n); // chỉ một trong hai khác rỗng
        return res;
    }
};