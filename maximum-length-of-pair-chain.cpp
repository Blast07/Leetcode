//646

int findLongestChain(vector<vector<int>>& pairs) {
    
	int n = pairs.size();

    
   	sort( pairs.begin(), pairs.end(), [](vector <int> v1, vector <int> v2)->bool {
		if (v1.size()!=2 || v2.size()!=2){
            return false;
        }
        if (v1[1] < v2[0])
			return true;
		else if (v2[1] < v1[0])
			return false;
		else
			return v1[1] <= v2[1];
	}); 

	vector <int> dp(n, 1);

	int res = 1;

    for (int i=1;i<n;i++){
		for (int j=i-1;j>=0;j--){
			if (pairs[j][1] < pairs[i][0]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		res = max(res, dp[i]);
	}

	return res;

}
