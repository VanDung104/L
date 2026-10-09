class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num:nums) count[num]++;
        vector<pair<int, int>> freq;
        for(auto &p: count)
        {
            freq.push_back({p.second, p.first});
        }
        sort(freq.rbegin(), freq.rend());
        vector<int> ans;
        for(int i = 0; i < k;++i)
        {
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};
