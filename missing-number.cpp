class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num=0;
        for (int i=0;i<nums.size();i++){
            num ^= nums[i];
            num ^= i;
        }
        num ^= int(nums.size());
        return num;
    }
};