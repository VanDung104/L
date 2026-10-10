class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        for(int i = 1; i < nums.size();++i)
        {
            if(nums[i]==nums[i-1])
            {
                cnt++;
            }
            else{
                if(cnt > (nums.size()/2)) return nums[i - 1];
                cnt = 1;
            }
        }
        return nums[nums.size()-1];
    }
};