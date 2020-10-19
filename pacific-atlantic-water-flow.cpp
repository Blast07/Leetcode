class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
       if(matrix.size()==0)
           return vector <vector <int>>();
        int m = matrix.size();
        int n = matrix[0].size();
        vector <vector <int>> visited(m, vector <int> (n,0));
        /*
            1 - pacific
            2 - atlantic
            3 - both
        */
        struct node {
            int row;
            int col;
            node(int r,int c):row(r), col(c){
                
            }
            node(){}
        };
        
        queue <node> q;
        //pacific corners left and top
        for (int i=0;i<m;i++){
            node new_node(i,0); 
            visited[i][0] = 1;
            q.push(new_node);
        }
        for (int i=1;i<n;i++){
            node new_node(0,i);
            visited[0][i] = 1;
            q.push(new_node);
        }
        //traversing low to high;
        while(!q.empty()){
            node front = q.front(); q.pop();
            int r = front.row;
            int c = front.col;
            if (r-1>=0 && visited[r-1][c]==0 && (matrix[r][c] <= matrix[r-1][c])){
                node new_node(r-1,c);
                q.push(new_node);
                visited[r-1][c] = 1;
            }
            
            if (r+1<m && visited[r+1][c]==0 && (matrix[r][c] <= matrix[r+1][c])){
                node new_node(r+1,c);
                q.push(new_node);
                visited[r+1][c] = 1;
            }
            
            if (c-1>=0 && visited[r][c-1]==0 && (matrix[r][c] <= matrix[r][c-1])){
                node new_node(r,c-1);
                q.push(new_node);
                visited[r][c-1] = 1;
            }
                
            if (c+1<n && visited[r][c+1]==0 && (matrix[r][c] <= matrix[r][c+1])){
                node new_node(r,c+1);
                q.push(new_node);
                visited[r][c+1] = 1;
            }
            
        }
        //right and bottom atlantic borders
        for (int i=0;i<m;i++){
            node new_node(i,n-1);
            visited[i][n-1] += 2;
            q.push(new_node);
        }
     
        for (int i=0;i<n-1;i++){
            node new_node(m-1,i);
            visited[m-1][i] += 2;
            q.push(new_node);
        }
        while (!q.empty()){
            
            node front = q.front(); q.pop();
            int r = front.row;
            int c = front.col;
            if (r-1>=0 && (visited[r-1][c]==0 ||visited[r-1][c]==1) && (matrix[r][c] <= matrix[r-1][c])){
                node new_node(r-1,c);
                q.push(new_node);
                visited[r-1][c] += 2;
            }
            
            if (r+1<m && (visited[r+1][c]==0 || visited[r+1][c]==1) && (matrix[r][c] <= matrix[r+1][c])){
                node new_node(r+1,c);
                q.push(new_node);
                visited[r+1][c] += 2;
            }
            
            if (c-1>=0 && (visited[r][c-1]==0 || visited[r][c-1]==1) && (matrix[r][c] <= matrix[r][c-1])){
                node new_node(r,c-1);
                q.push(new_node);
                visited[r][c-1] += 2;
            }
                
            if (c+1<n && (visited[r][c+1]==0 || visited[r][c+1]==1) && (matrix[r][c] <= matrix[r][c+1])){
                node new_node(r,c+1);
                q.push(new_node);
                visited[r][c+1] += 2;
            }
            
            
        }
        vector <vector <int>> v;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (visited[i][j] == 3)
                    v.push_back({i,j});
            }
        }
        
        return v;
    }
};