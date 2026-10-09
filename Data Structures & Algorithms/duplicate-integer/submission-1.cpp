class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> cnt;
        for(int num: nums)
        {
            if(cnt.count(num)) return true;
            cnt.insert(num);
        }
        return false;
    }
};