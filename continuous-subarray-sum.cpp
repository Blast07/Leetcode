class Solution {
public:
    bool checkSubarraySum(vector <int> &nums, int k){
        if (!nums.size())
            return false;
        if (k==0){
            for (int i=0;i<nums.size()-1;i++){
                if (!nums[i] && !nums[i+1]) 
                    return true;
                   
            }
            return false;
            
        }
        int cur_sum = 0;
        unordered_map <int, int> mp;
        mp[0] = -1;
    
        for (int i=0;i<nums.size();i++){
            cur_sum = (cur_sum + nums[i])%k;	
            if (mp.find(cur_sum) != mp.end()){
                if (i-mp[cur_sum]>1)
                    return true;
            }else
                mp[cur_sum] = i;
        }
    
        return false;
    }

};