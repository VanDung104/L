class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto &p: count)
        {
            int num = p.first;
            int freq = p.second;
            bucket[freq].push_back(num);
        }
        vector<int> ans;
        for(int i =n; i >=1;--i)
        {
            for(int num: bucket[i])
            {
                ans.push_back(num);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
