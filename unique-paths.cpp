class Solution {
public:
    
int uniquePathsutil(int i,int j,int m,int n,int **DP){
	if (i>m || j>n)
		return 0;
    else if(DP[i][j]!=-1)
        return DP[i][j];
	else if (i==m && j==n){
		DP[i][j] = 1;
	}
	else{
		DP[i][j]  = uniquePathsutil(i+1,j,m,n,DP) + uniquePathsutil(i,j+1,m,n,DP);
	}
	return DP[i][j];
}

    int uniquePaths(int m, int n) {
        int **DP = new int*[m];
	for (int i=0;i<m;i++){
		DP[i] = new int[n];
		for(int j=0;j<n;j++)
			DP[i][j] = -1;
	}
	return uniquePathsutil(0,0,m-1,n-1,DP);

    }
};