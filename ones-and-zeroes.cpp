//474

int findMaxForm(vector<string>& strs, int m, int n) {
	vector <vector<int>> dp(m+1, vector <int> (n+1, 0));

	for (string str:strs){
		int zeros = 0;
		int ones = 0;

		for(char ch:str){
			if (ch == '0')
				zeros++;
			else
				ones++;
		}

		for (int i=m;i>=0;i--){
			for(int j=n;j>=0;j--){
				if (i-zeros >=0 && j-ones >= 0){
					dp[i][j] = max(dp[i][j], 1+dp[i-zeros][j-ones]);
				}
			}
		}

	}

	return dp[m][n];


}

