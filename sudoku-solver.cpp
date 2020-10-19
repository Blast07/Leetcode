class Solution {
public:
    int f(int i,int j){
        int x = i/3; int y = j/3;
        return 3*x+y;
    }
    bool sudoku(vector <vector <char>> &board, int cur,vector <vector <bool>> &rows,
                vector <vector <bool>> &cols,vector <vector <bool>> &blocks){
        if (cur==81)
            return true;
        int i = cur/9;
        int j = cur%9;
        if(board[i][j]!='.'){
            return sudoku(board,cur+1,rows,cols,blocks);
        }else{
            for (int n=1;n<=9;n++){
                if ((!rows[i][n] && !cols[j][n]) && !blocks[f(i,j)][n]){
                    board[i][j] = '0'+n;
                    rows[i][n] = true;
                    cols[j][n] = true;
                    blocks[f(i,j)][n] = true;
                    if (sudoku(board,cur+1,rows,cols,blocks))
                        return true;
                    rows[i][n] = false;
                    cols[j][n] = false;
                    blocks[f(i,j)][n] = false;
                    
                }
            }
            board[i][j] = '.';
            return false;
        }
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        vector <vector<bool>> rows(10,vector <bool>(10,false));
        vector <vector<bool>> cols(10,vector <bool>(10,false));
        vector <vector<bool>> blocks(10,vector<bool>(10,false));
        //initialize these vectors first 
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
               if(board[i][j]!='.'){ 
                    rows[i][board[i][j]-'0'] = true;
                    cols[j][board[i][j]-'0'] = true;
                   // cout<<f(i,j)<<endl;
                    blocks[f(i,j)][board[i][j]-'0'] = true;
               }
            }
        }
        cout<<"before calling"<<endl;
        sudoku(board,0,rows,cols,blocks);  
    }
};