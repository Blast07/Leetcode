//1049

int lastStoneWeightII(vector<int>& stones) {
	int totalSum = accumulate(stones.begin(), stones.end(), totalSum);
	int target = totalSum/2, n = stones.size();
	
	vector<int> dp(target+1, 0);
	//cout<<target<<endl;
	for(int stone: stones)
	    for(int j = target; j >=stone; j--){
	        dp[j] = max(dp[j] , stone + dp[j - stone]);
	    }
	
	return totalSum - 2 * dp[target];
}
