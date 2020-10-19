class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector <int> res;
        long long int a=0,b=0;
        long long int xor_ab = 0;
        for (int i=0;i<nums.size();i++){
            xor_ab ^= nums[i];
        }
        int diff_bit=0;
        diff_bit = (xor_ab&(xor_ab-1))^xor_ab;
        
        for (int i=0;i<nums.size();i++){
            if (nums[i]&diff_bit)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        
        res.push_back(a);
        res.push_back(b);
        
        return res;
    }
};