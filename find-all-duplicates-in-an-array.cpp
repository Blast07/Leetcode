class Solution {
public:
    vector <int> findDuplicates(vector <int> &nums){
	// 1<=nums[i]<=n
	vector <int> res;
	for (int i=0;i<nums.size();i++){
		if (nums[abs(nums[i])-1] > 0 )
			nums[abs(nums[i])-1] *= -1; //mark as -ve or visited
		else // already -ve / visited
			res.push_back(abs(nums[i]));

	}
	return res;

}

};