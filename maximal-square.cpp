class Solution {
public:
    

int maximalSquare(vector<vector<char>>& matrix) {
    int n=matrix.size();
    
    if(n==0)
        return 0;
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    int ans=0;
    for (int row =0;row<n;row++){
        for (int col=0;col<m;col++){
            if(matrix[row][col]=='1'){
                dp[row][col] =1;
                if(row>0 && col>0){
                    dp[row][col]+=min(min(dp[row][col-1],dp[row-1][col]),dp[row-1][col-1]);
                }
                ans =max(ans,dp[row][col]);
                
            }
        }
    }
    return ans*ans;
    
}


};