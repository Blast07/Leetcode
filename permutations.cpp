class Solution {
public:
    void permutations(vector <int> &nums,int pos,vector <vector <int>> &res){
        if (pos==nums.size()-1){
            res.push_back(nums);
        }else {
            for (int i=pos;i<nums.size();i++){
                vector <int> temp = nums;
                swap(temp[pos],temp[i]);
                permutations(temp,pos+1,res);
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> res;
        permutations(nums,0,res);
        return res;
    }
};