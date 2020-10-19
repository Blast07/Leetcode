class Solution {
public:
        void target(vector <int>&arr, int i,int size,int sum,vector <int> &nums, set <vector<int>> &set_of_nums){
	
	if(i<size){
		if (sum<0)
			return;

		if(arr[i]==sum){
			nums.push_back(arr[i]);
			set_of_nums.insert(nums);
			nums.pop_back();
			
		}

		//case1 including this and not incrementin
		nums.push_back(arr[i]);
		target(arr,i,size,sum-arr[i],nums,set_of_nums);

		//case1 including this and increment
		target(arr,i+1,size,sum-arr[i],nums,set_of_nums);

		//excluding this
		nums.pop_back();
		target(arr,i+1,size,sum,nums,set_of_nums);
	}
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int sum) {
        set <vector <int>> set_of_nums;
        vector <int> nums;
        target(candidates,0,candidates.size(),sum,nums,set_of_nums);
        vector <vector <int>> result(set_of_nums.begin(),set_of_nums.end());
        return result;
    }
    


};