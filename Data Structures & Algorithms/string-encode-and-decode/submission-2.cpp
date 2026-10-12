class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(string s: strs)
        {
            encoded += to_string(s.size()) + "#" +s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size())
        {
            int j = i;
            // tim vi tri '#' dau tien ke tu vi tri i
            while(s[j]!='#') j++;
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j+1, length);
            res.push_back(str);
            i = j + 1 + length;
        }
        return res;
    }
};
