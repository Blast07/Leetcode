class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start =0;
        int end =0;
        int cur_sum=0;
        int min_len = INT_MAX;
        int n = nums.size();
        for (int i=0;i<n;i++){
            if(nums[i]>=s)
                return 1;
        }
        
        while(start<n){
            while(cur_sum<s && end<n){
                cur_sum += nums[end++];
            }
            if (end>=n && cur_sum<s){
                break;
            }
            
            min_len = min(min_len, end-start);
            
            while(start<end){
                cur_sum -= nums[start++];
                if (cur_sum<s)
                    break;
                min_len = min(min_len, end-start);
            }
            
        }
        if (min_len==INT_MAX)
            return 0;
        return min_len;
    }
};