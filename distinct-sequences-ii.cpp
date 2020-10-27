//940

/*
int distinctSubseqII(string s) {

	vector <int> dp(26, 0);
	int total = 0;

	for (int i=0;i<s.size();i++){
		int total_at_i = (total + 1 - dp[s[i] - 'a']);
		total = total + total_at_i;
		dp[s[i] - 'a'] += total_at_i; 
	}

	return total;
}
*/

const int M = 1000000007;
int distinctSubseqII(string s) {

	vector <int> dp(26, 0);
	int total = 0;

	for (int i=0;i<s.size();i++){
		int total_at_i = ((long long)total%M + 1 - dp[s[i] - 'a']%M + M)%M;
		total = (total%M + (long long)total_at_i)%M;
		dp[s[i] - 'a'] = (dp[s[i] - 'a']%M + (long long)total_at_i)%M; 
	}

	return total;
}

