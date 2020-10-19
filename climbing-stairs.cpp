class Solution {
public:
    int totalWayToTop(int cur,int n,int *DP){
	if (cur>n)
		return 0;
	else if (DP[cur]!=-1)
		return DP[cur];
	else if (cur==n)
		DP[cur] = 1;
	else{
		DP[cur] = totalWayToTop(cur+1,n,DP) + totalWayToTop(cur+2,n,DP);
	}
	return DP[cur];
}

    int climbStairs(int n) {
        int DP[n+1];
        for (int i=0;i<=n;i++)
            DP[i] = -1;
        return totalWayToTop(0,n,DP);
    }
};