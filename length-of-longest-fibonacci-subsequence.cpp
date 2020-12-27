//873

int lenLongestFibSubseq(vector<int>& a) {
	int n = a.size();	
	unordered_map <int,int> mp;
	vector <vector<int>> dp(n, vector <int>(n, 2));

	for (int i=0;i<n;i++){
		mp[a[i]] = i;	
	}
	int res = 0;

	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			int before_ai = a[j] - a[i];
			if (before_ai >= a[i])
				break;

			auto it = mp.find(before_ai);
			if (it == mp.end())
				continue;
			int k = it->second;

			dp[i][j] = dp[k][i] + 1;

			res = max(res, dp[i][j]);
		}
	}

	return res;
}
