class Solution {
public:
int uniquePathsutil(int i,int j,int m,int n,int **DP,vector <vector<int>> grid){
	if (i>m || j>n)
		return 0;
	else if(DP[i][j]!=-1)
		return DP[i][j];
    else if(grid[i][j]==1)
		DP[i][j] = 0;
	else if (i==m && j==n){
		DP[i][j] = 1;
	}
	else{
		DP[i][j]  = uniquePathsutil(i+1,j,m,n,DP,grid) + uniquePathsutil(i,j+1,m,n,DP,grid);
	}
	return DP[i][j];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	int **DP = new int*[m];
	for (int i=0;i<m;i++){
		DP[i] = new int[n];
		for(int j=0;j<n;j++)
			DP[i][j] = -1;
	}
   return uniquePathsutil(0,0,m-1,n-1,DP,obstacleGrid);
}

};