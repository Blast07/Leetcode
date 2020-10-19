class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int nb[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){//try BFS from every land
                    queue <pair<int,int>> q;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair <int,int> front= q.front();q.pop();
                        int fi = front.first;
                        int fj = front.second;
                        
                        for(int i=0;i<4;i++){
                            int x = fi + nb[i][0]; int y = fj + nb[i][1];
                            if ((x>=0 && x<n) && (y>=0 && y<n)){
                                if (grid[x][y]==0 || grid[x][y] > grid[fi][fj]+1){
                                    grid[x][y] = grid[fi][fj] + 1;
                                    q.push(make_pair(x,y));
                                }
                                    
                            }
                        }
                        
                    }
                    
                }
            }
        }
        int m = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]>m)
                    m = grid[i][j];
            }
        }
        return (m==1) ? -1:m-1;
    }
};