class Solution {
public:
    int uniqueBST(int start,int n,int **DP){
	if (start==n){
		DP[start][n] = 1;
		return 1;
	}
	else if (start>n)
		return 0;
	else if (DP[start][n]!=-1)
		return DP[start][n];
	else {
		int count = 0;
		for (int i=start;i<=n;i++){
			int left  = uniqueBST(start,i-1,DP);
			int right = uniqueBST(i+1,n,DP);
			if (left==0 && right==0)
				count+=0;
			else if(left==0)
				count+=right;
			else if(right==0)
				count+=left;
			else count+=left*right;
		}
		DP[start][n] = count;
		return count;
		
	}
    }
    


    int numTrees(int n) {
       	int **DP = new int*[n+1];
	for(int i=1;i<=n;i++){
		DP[i] = new int[n+1];
		for(int j=0;j<=n;j++)
			DP[i][j] = -1;
	}

        
        return uniqueBST(1,n,DP);
    }
};