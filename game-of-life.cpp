class Solution {
public:
    void gameOfLife(vector <vector<int>> &board){
    int n = board.size();
    int m = board[0].size();
    vector <vector<int>> nbors{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ones=0;
            for(auto v:nbors){
                int x = i+v[0];
                int y = j+v[1];
                if(x>=0 && x<n && y>=0&&y<m){
                if (board[x][y]==1 || board[x][y]==-1)
                    ones++;
 }               
            }
            if (board[i][j]){
                if (ones<2 || ones>3)
                    board[i][j]= -1;
                
            }else{
                if (ones==3)
                    board[i][j] = 2;
            }
            
            
        }
    }
    
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if(board[i][j]==2)
                board[i][j]=1;
            else if(board[i][j]==-1)
                board[i][j] = 0;
            
        }
    }
    
}
};