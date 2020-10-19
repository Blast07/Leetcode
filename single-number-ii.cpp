class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32] = {0};
        for (int i=0;i<nums.size();i++){
            for (int j=0;j<32;j++){
                if(nums[i]>>j&1)
                    bits[j]++;
            }
        }
        int res=0;
        for (int j=0;j<32;j++){
            if (bits[j]%3!=0)
                res |= 1<<j;
        }
        return res;
    }
};