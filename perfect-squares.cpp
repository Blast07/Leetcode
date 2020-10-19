class Solution {
public:
    
  //bfs solution
  int numSquares(int n){
      int root = pow(n,0.5);
      vector <bool> visited(n+1, false);
      vector <int> level(n+1, 0);
      queue <int> q;
      q.push(0);
      visited[0] = true;
      while(!q.empty()){
          int front = q.front();
          q.pop();
          if (front==n)
              return level[front];
          for (int i=1;i<=root && front+i*i<=n;i++){
              int node = front+i*i;
              if (!visited[node]){
                  visited[node] = true;
                  level[node] = level[front]+1;
                  q.push(node);
              }
          }
      }
      return level[n];
  }
  /*dp solution
  int numSquares(int n) {
        int root = pow(n,0.5);
        vector <vector <int>> dp(root+1, vector <int>(n+1,0));
        for (int i=1;i<=n;i++)
            dp[1][i] = i;
        for (int i=2; i<=root;i++){
            for (int j=1;j<=n;j++){
                if (i*i>j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-i*i]);
                }
            }
        }
        return dp[root][n];
    }
  */
};