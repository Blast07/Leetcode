class Solution {
public:
    void combinationSum(vector <int> &vec, int i,int size,int sum,int remaining_sum,multiset <int> &nums,set <multiset <int>> &set_of_nums){
	if (sum<0)
		return;
	if (remaining_sum<sum)
		return;
	if (i<size){
		if (vec[i]==sum){
			auto it = nums.insert(vec[i]);
			set_of_nums.insert(nums);
			nums.erase(it);
		}

		//including
		auto it = nums.insert(vec[i]);
		combinationSum(vec,i+1,size,sum-vec[i],remaining_sum-vec[i],nums,set_of_nums);
		nums.erase(it);
		//excluding
		combinationSum(vec,i+1,size,sum,remaining_sum-vec[i],nums,set_of_nums);

	}

}


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
           multiset <int> nums;
           set <multiset <int>> set_of_nums;
           int remaining_sum = 0;
           for (auto i:candidates)
               remaining_sum += i;
           combinationSum(candidates,0,candidates.size(),target,remaining_sum,nums,set_of_nums);
           vector <vector <int>> result;
           for (auto i:set_of_nums){
               result.push_back(vector <int> (i.begin(),i.end()));
           }
           return result;
    }
};