class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1 ;
        int res=0; 
        int start = 0; 
        for (int i=0;i<nums.size();i++){
            prod = prod*nums[i];
            while(prod>=k && start<=i){
                prod = prod/nums[start];
                start++;
            }
            if (start<=i)
                res = res + i-start+1;
        }
        return res;
    }
};