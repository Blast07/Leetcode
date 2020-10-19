class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int DP[s1.size()+1][s2.size()+1];
        for (int i=0;i<=s1.size();i++){
            for (int j=0;j<=s2.size();j++){
                DP[i][j] = 0;
            }
        }
        for (int i=1;i<=s1.size();i++){
            for (int j=1;j<=s2.size();j++){
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
                if (s1[i-1]==s2[j-1])
                    DP[i][j] = max(DP[i][j],1+DP[i-1][j-1]);
            }
        }
        return DP[s1.size()][s2.size()];
    }
};