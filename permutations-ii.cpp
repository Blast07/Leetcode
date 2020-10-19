class Solution {
public:
    vector <vector<int>> res;
    
    void permute(vector <int> nums,int cur){
        if (cur==nums.size())
            res.push_back(nums);
        else{
            for (int i=cur;i<nums.size();i++){
                  if (i!=cur && nums[i]==nums[cur]){
                       continue;
                  }
                  swap(nums[i], nums[cur]);
                  permute(nums,cur+1);
            }
        }
    }
    vector<vector<int>>permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        permute(nums,0);
        return res;
    }
};