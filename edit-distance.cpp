class Solution {
public:
    int minDistance(string A, string B) {
    vector <vector <int>> DP(A.size()+1, vector <int>(B.size()+1,0));
    for (int i=0;i<=A.size();i++)
        DP[i][0] = i;
    
    for (int i=0;i<=B.size();i++)
        DP[0][i] = i;
    
    for (int i=1;i<=A.size();i++){
        for (int j=1;j<=B.size();j++){
            if (A[i-1]==B[j-1])
                DP[i][j] = DP[i-1][j-1];
            else{
                DP[i][j] = 1+min(min(DP[i][j-1],DP[i-1][j]),DP[i-1][j-1]);
            }
        }
    }
    return DP[A.size()][B.size()];
    }
};