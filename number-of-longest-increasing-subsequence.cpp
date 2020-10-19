class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        int LIS[nums.size()];
        int count[nums.size()];
        for (int i=0;i<nums.size();i++){
            LIS[i] = 1;
            count[i] = 1;
        }
        int longest = 1;
        
        for (int i=1;i<nums.size();i++){
            for (int j=0;j<i;j++){
                if (nums[j] < nums[i]){
                    if (LIS[j]+1>LIS[i]){
                        LIS[i] = LIS[j]+1;
                        count[i] = count[j];
                    }else if(LIS[j] +1 == LIS[i])
                        count[i] +=count[j];
                }
            }
            if (LIS[i]>longest)
                longest = LIS[i];
        }
        int res = 0; 
        for (int i=0;i<nums.size();i++){
            if (LIS[i]==longest)
                res += count[i];
        }
        return res;
    }
};