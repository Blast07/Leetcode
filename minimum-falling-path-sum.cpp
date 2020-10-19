class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector <vector <int>> dp(n, vector <int>(n,INT_MAX));
        
        for(int i=0;i<n;i++)
            dp[0][i] = A[0][i];
        
        for (int i=1;i<n;i++){
            for (int j=0;j<n;j++){
                for (int k=j-1;k<=j+1;k++){
                    if (k>=0 && k<n){
                        dp[i][j] = min(dp[i][j],dp[i-1][k]+A[i][j]);
                    }
                    
                }
            }
        }
        int res = INT_MAX;
        for (int i=0;i<n;i++){
            res = min(dp[n-1][i],res);
        }
        return res;
    }
};