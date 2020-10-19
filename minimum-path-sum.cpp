class Solution {
    int m;
    int n;
    vector <vector<int>> map;
public:
    

int minPathSum(vector<vector<int>>& grid) {
  
  if(!grid.size())
      return 0;
  else{
     int n=grid.size();
     int m=grid[0].size();
     
     for (int i=n-2;i>=0;i--)
         grid[i][m-1]+=grid[i+1][m-1];
     for (int j=m-2;j>=0;j--)
         grid[n-1][j]+=grid[n-1][j+1];
    
     for(int i=n-2,j=m-2;i>=0&&j>=0;i--,j--){
     for (int x=i;x>=0;x--)
         grid[x][j] += min(grid[x+1][j],grid[x][j+1]);
         
    for (int y=j-1;y>=0;y--)
        grid[i][y] += min(grid[i+1][y],grid[i][y+1]);
         
         
     }
     return grid[0][0];
  }
  
        
}
};