class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string fi = strs[0];
        for(int i = 0; i < fi.size();++i)
        {
            char c = fi[i];
            for(int j = 1; j < strs.size(); ++j)
            {
                if(i >= strs[j].size()||strs[j][i] != c)
                {
                    return fi.substr(0, i);
                }
            }
        }
        return fi;
    }
};