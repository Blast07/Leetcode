class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector <int>> visited(n,vector <int>(m,-1));
        queue<pair<int,int>> q;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
               if (grid[i][j]==2){//rotten
                  q.push(make_pair(i,j));
                  visited[i][j] = 0;
               } 
            }
        }
        
        while(!q.empty()){
            pair <int,int> front = q.front(); q.pop();
            int i = front.first;
            int j = front.second;
            if (i-1>=0 && visited[i-1][j]==-1){
                if(grid[i-1][j]==1){
                    grid[i-1][j] = 2;
                    visited[i-1][j] = visited[i][j]+1;
                    q.push(make_pair(i-1,j));
                }
            }
            
            if (i+1<n && visited[i+1][j]==-1){
                if(grid[i+1][j]==1){
                    grid[i+1][j] = 2;
                    visited[i+1][j] = visited[i][j]+1;
                    q.push(make_pair(i+1,j));
                }
            }
            
            if (j-1>=0 && visited[i][j-1]==-1){
                if(grid[i][j-1]==1){
                    grid[i][j-1] = 2;
                    visited[i][j-1] = visited[i][j]+1;
                    q.push(make_pair(i,j-1));
                }
            }
            if (j+1<m && visited[i][j+1]==-1){
                if(grid[i][j+1]==1){
                    grid[i][j+1] = 2;
                    visited[i][j+1] = visited[i][j]+1;
                    q.push(make_pair(i,j+1));
                }
            }
        }
        int max_ = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1)
                    return -1;
                if(visited[i][j]!=-1)
                    max_ = max(max_,visited[i][j]);
            }
        }
        return max_;
        
    }
};