class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int cnt =0;
        for(int num: nums)
        {
            if(cnt==0)
            {
                candidate = num;
                cnt = 1;
            }
            else
            {
                cnt += ((candidate==num)?1:-1);
            }
        }
        return candidate;
    }
};