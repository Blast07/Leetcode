class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector <vector <int>> G(N+1,vector <int>(N+1,INT_MAX));
        for (int i=0;i<times.size();i++){
            G[times[i][0]][times[i][1]] = times[i][2];
        }
        for (int k=1;k<=N;k++){
            for (int i=1;i<=N;i++){
                for (int j=1;j<=N;j++){
                    if (!(G[i][k]==INT_MAX || G[k][j]==INT_MAX))
                        G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
                }
            }
        }
        int res=0;
        for (int i=1;i<=N;i++){
            if (i==K)
                continue;
            if (G[K][i]==INT_MAX)
                return -1;
            else res = max(G[K][i],res);
        }
        return res;
    }
};