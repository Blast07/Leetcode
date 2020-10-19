class Solution {
public:
    int checkMines(vector <vector <char>> &board,int i,int j){
        if ( !((i>=0 && i<board.size()) 
            && (j>=0 && j<board[0].size())))
            return 0;
        else{
            if(board[i][j]=='M')
                return 1;
            else return 0;
        }
    }
    void minesweeper(vector <vector <char>> &board,int i,int j){
        if ( !((i>=0 && i<board.size()) 
            && (j>=0 && j<board[0].size())))
            return;
        else{
            if (board[i][j]=='M'){
                board[i][j] = 'X';
                return;
            }else if(board[i][j]=='E'){
                int mines=0;
                mines += checkMines(board,i-1, j);
                mines += checkMines(board,i+1, j);
                mines += checkMines(board,i, j-1);
                mines += checkMines(board,i, j+1);
                mines += checkMines(board,i-1,j-1);
                mines += checkMines(board,i+1,j+1);
                mines += checkMines(board,i-1,j+1);
                mines += checkMines(board,i+1,j-1);
                if (mines>0){
                    board[i][j] = '0'+mines;
                }else{
                    board[i][j] = 'B'; 
                    minesweeper(board,i-1, j);
                    minesweeper(board,i+1, j);
                    minesweeper(board,i, j+1);
                    minesweeper(board,i, j-1);
                    minesweeper(board,i-1, j-1);
                    minesweeper(board,i+1, j+1);
                    minesweeper(board,i-1, j+1);
                    minesweeper(board,i+1, j-1);
                }
                
            }
                
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        minesweeper(board, click[0],click[1]);
        return board;
    }
};