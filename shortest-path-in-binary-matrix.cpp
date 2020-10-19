class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if (n==0)
            return 1;
        if (grid[0][0]==1)
            return -1;
        vector <vector <int>> visited(n,vector <int>(n,0));
        queue <pair<int,int>> q;
        q.push(make_pair(0,0));
        visited[0][0] = 1;
        
        while(!q.empty()){
            pair <int,int> front = q.front();q.pop();
            int i=front.first;
            int j=front.second;
            if (i==n-1 && j==n-1)
                return visited[n-1][n-1];
            //normal 4 directions            
            if (i-1 >=0 && (!visited[i-1][j] && !grid[i-1][j])){
               q.push(make_pair(i-1,j)); 
               visited[i-1][j] = visited[i][j] +1;
            }
            if (i+1 <n && (!visited[i+1][j] && !grid[i+1][j])){
               q.push(make_pair(i+1,j)); 
               visited[i+1][j] = visited[i][j] +1;
            }
            if (j-1 >=0 && (!visited[i][j-1] && !grid[i][j-1])){
               q.push(make_pair(i,j-1)); 
               visited[i][j-1] = visited[i][j] +1;
            }
            if (j+1 <n && (!visited[i][j+1] && !grid[i][j+1])){
               q.push(make_pair(i,j+1)); 
               visited[i][j+1] = visited[i][j] +1;
            }
            
            //4 diagonols
            
            if ((i-1 >=0 && j-1>=0) && (!visited[i-1][j-1] && !grid[i-1][j-1])){
               q.push(make_pair(i-1,j-1)); 
               visited[i-1][j-1] = visited[i][j] +1;
            }
            if ((i-1 >=0 && j+1<n) && (!visited[i-1][j+1] && !grid[i-1][j+1])){
               q.push(make_pair(i-1,j+1)); 
               visited[i-1][j+1] = visited[i][j] +1;
            }
            if ((i+1 <n && j+1<n) && (!visited[i+1][j+1] && !grid[i+1][j+1])){
               q.push(make_pair(i+1,j+1)); 
               visited[i+1][j+1] = visited[i][j] +1;
            }
            if ((i+1 <n && j-1>=0) && (!visited[i+1][j-1] && !grid[i+1][j-1])){
               q.push(make_pair(i+1,j-1)); 
               visited[i+1][j-1] = visited[i][j] +1;
            }
        }
        
        
       return -1;  
    }
};