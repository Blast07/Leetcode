class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.size()==0)
            return vector <vector <int>>();
        int r = matrix.size();
        int c = matrix[0].size();
        vector <vector <int>> output(r, vector <int> (c,0));
        vector <vector <int>> visited(r, vector <int> (c,false));
        queue <vector <int>> q;
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if(!matrix[i][j]){
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            vector <int> rc = q.front(); q.pop();
            int row = rc[0];
            int col = rc[1];
            if(row-1>=0 && !visited[row-1][col]){
                output[row-1][col] = output[row][col]+1;
                q.push({row-1,col});
                visited[row-1][col] = true;
            }
            
            if(row+1<r && !visited[row+1][col]){
                output[row+1][col] = output[row][col]+1;
                q.push({row+1,col});
                visited[row+1][col] = true;
            }
            if(col-1>=0 && !visited[row][col-1]){
                output[row][col-1] = output[row][col]+1;
                q.push({row,col-1});
                visited[row][col-1] = true;
            }
            if(col+1<c && !visited[row][col+1]){
                output[row][col+1] = output[row][col]+1;
                q.push({row,col+1});
                visited[row][col+1] = true;
            }
        }
        
    return output;
    }
};