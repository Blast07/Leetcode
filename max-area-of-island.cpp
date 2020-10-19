class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector <vector <bool>> visited(n, vector <bool>(m,false));
        int max_area = 0;
        
        vector <vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}}; 
        
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(grid[i][j] && !visited[i][j]){
                    //DFS or BFS
                    stack <pair<int,int>> st;
                    st.push(make_pair(i,j));
                    visited[i][j] = true;
                    int count=0;
                    while(!st.empty()){
                        pair <int,int> top = st.top(); st.pop();
                        count++;
                        for(int d=0;d<dir.size();d++){
                            int x = top.first + dir[d][0];
                            int y = top.second + dir[d][1];
                            if ((x>=0 && x<n) && (y>=0 && y<m)){
                                if(grid[x][y] && !visited[x][y]){
                                    st.push(make_pair(x,y));
                                    visited[x][y] = true;
                                }
                            }
                        }
                    }
                    max_area = max(max_area, count);
                }
            }
        }
        return max_area;
    }
};