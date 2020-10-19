class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far =0;
        int max_till_here =0;
        int m=INT_MIN;
        for (auto x:nums){
            max_till_here = max(0,max_till_here + x);
            max_so_far = max(max_so_far,max_till_here);
            m = max(m,x);
        }
         if (m<0)
             return m;
        else return max_so_far;
    }
};