//368

vector<int> largestDivisibleSubset(vector<int>& nums) {
	int n = nums.size();    
    if(n == 0)
        return {};
    if (n == 1)
        return nums;
    
    sort(nums.begin(), nums.end());

	vector <int> dp(n,1);
	vector <int> par(n, -1);

	int max_len = 1;
	int max_ind = 0;

	for (int i=1;i<n;i++){
		for (int j=i-1;j>=0;j--){
			if (nums[i]%nums[j] == 0){
				if (1 + dp[j] > dp[i]){
					dp[i] = 1+dp[j];
					par[i] = j;
				}
			}
		}
		if (max_len < dp[i]){
            max_len = dp[i];
			max_ind = i;
		}
	}

	vector <int> res;

	while(max_ind!=-1){
		res.push_back(nums[max_ind]);
		max_ind = par[max_ind];
	}

	return res;

}
