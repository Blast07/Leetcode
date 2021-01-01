//377

int combinationSum4(vector<int>& nums, int target) {
	
	int n = nums.size();

	vector <unsigned int> dp(target+1, 0);
	dp[0] = 1;

	for (int i=1;i<=target;i++){
		for (int cur:nums){
			if (cur <= i){
				dp[i] += dp[i-cur];
			}
		}
	}

	return dp[target];

}
