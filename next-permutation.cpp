class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for (int i = n-2;i>=0;i--){
            int x = INT_MAX;
            ind = -1;
            for (int j=n-1;j>i;j--){
               if (nums[j] > nums[i] && nums[j]<x){
                   x = nums[j];
                   ind = j;
               }
                   
            }
            
            if (ind !=-1){
                swap(nums[i],nums[ind]);
                sort(nums.begin()+i+1,nums.end());
                break;
            }
                
        }
        if (ind==-1)
            reverse(nums.begin(),nums.end());
    }
};