class Solution {
public:
    /*
    int longestS(vector <int> &nums, int cur, int prev){
        if (cur==nums.size())
            return 0;
        else {
            if (nums[cur] > prev)
                return max(1+longestS(nums,cur+1,nums[cur]),longestS(nums,cur+1,prev));
            else
                return longestS(nums,cur+1,prev);
        }
        
    }*/
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        int LIS[nums.size()];
        for (int i=0;i<nums.size();i++)
            LIS[i] = 1;
        int longest = 1;
        for (int i=1;i<nums.size();i++){
            for (int j=0;j<i;j++){
                if (nums[j]<nums[i] && LIS[j]+1>LIS[i])
                    LIS[i] = LIS[j]+1;
            }
            if (LIS[i]>longest)
                longest = LIS[i];
        }
        return longest;
    //    return longestS(nums,0,INT_MIN);
    }
};