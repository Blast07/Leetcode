class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = pow(2,nums.size());
        vector <vector <int>> power_set(n,vector <int>());
        for (int i=0;i<nums.size();i++){
            for (int j=0;j<n;j++){
                if ((j>>i)&1){
                    power_set[j].push_back(nums[nums.size()-1-i]);
                }
            }
        }
        return power_set;
    }
};