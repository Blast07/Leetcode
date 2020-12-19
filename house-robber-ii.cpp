//213

int rob(vector <int> &nums){
	int n = nums.size();
	if (n<=3)
		return *max_element(nums.begin(), nums.end());

	
	int prev2 = nums[0];
	int prev1 = max(nums[0], nums[1]);

	//excluding last element
	for (int i=2;i<n-1;i++){
		int t = max(prev1, prev2 + nums[i]);
		prev2 = prev1;
		prev1 = t;
	}

	int ans1 = prev1;

	prev2 = nums[1];
	prev1 = max(nums[1], nums[2]);
	
	//excluding first element
	for (int i=3;i<n;i++){
		int t = max(prev1, prev2+nums[i]);
		prev2 = prev1;
		prev1 = t;
	}

	return max(ans1, prev1);
}
