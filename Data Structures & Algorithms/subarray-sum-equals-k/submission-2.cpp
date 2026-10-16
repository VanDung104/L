class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0;
        int count = 0;
        prefixSumCount[0]=1;
        for(int num: nums)
        {
            currentSum += num;
            int target = currentSum - k;
            if(prefixSumCount.count(target))
            {
                count+=prefixSumCount[target];
            }
            prefixSumCount[currentSum] +=1;
        }
        return count;
    }
};