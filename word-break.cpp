class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        vector <vector <bool>> dp(s.size(),vector <bool>(s.size(),false));
        set <string> wordDict(dict.begin(),dict.end());
        for (int i=0;i<s.size();i++){
            if (wordDict.find(string(s,i,1))!=wordDict.end())
                dp[i][i] = true;
            else dp[i][i] = false;
        }
        
        for (int l=2;l<=s.size();l++){
          
            for (int i=0;i<=s.size()-l;i++){
                int j = i+l-1;
                if (wordDict.find(string(s,i,j-i+1))!=wordDict.end()){
                    dp[i][j] = 1;
                }else{
                    for (int k=i;k<j;k++){
                        if (dp[i][k]&&dp[k+1][j]){
                            dp[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][s.size()-1];
    }
};