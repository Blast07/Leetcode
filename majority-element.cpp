class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //assuming majority element exists
        int bits[32] = {0};
        for (int i=0;i<nums.size();i++){
            int num = nums[i];
            for(int j=0;j<32;j++){
                if (num&1==1){
                    bits[j]++;
                }
                num >>= 1;
            }
        }
        int majority=0;
        for (int i=0;i<32;i++){
            if(bits[i]>nums.size()/2){
                majority |= 1<<i;
            }
        }
        return majority;
    }
};