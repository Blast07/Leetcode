class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector <int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0;i<n-2;i++){
            if (i!=0 && nums[i]==nums[i-1])
                continue;
            int sum = target - nums[i];
            for (int j=i+1;j<n-1;j++){
                if (j!=i+1 && nums[j]==nums[j-1])
                    continue;
                int temp = sum - nums[j];
                int s = j+1; int e = n-1;
                while(s<e){
                    int t = nums[s] + nums[e];
                    if (temp==t){
                        res.push_back({nums[i],nums[j],nums[s],nums[e]});
                        s++;
                        while(s<e && nums[s]==nums[s-1])
                            s++;
                        e--;
                        while(s<e && nums[e]==nums[e+1])
                            e--;
                    }else if(t>temp)
                        e--;
                    else
                        s++;
                    
                }
                
            }
        }
        return res;
    }
};