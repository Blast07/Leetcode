class Solution {
public:
void floodFill(char old_c, char new_c,int i,int j,vector <vector <char>> &board){
	if ((i>=0 && i<board.size()) && (j>=0 && j<board[0].size())){
		if (board[i][j]!=old_c)
			return;
		else{
			board[i][j] = new_c;
			floodFill(old_c,new_c,i,j-1,board);
			floodFill(old_c,new_c,i,j+1,board);
			floodFill(old_c,new_c,i+1,j,board);
			floodFill(old_c,new_c,i-1,j,board);

		}
	}
	

}

void fillSurrounded(vector <vector <char>> &board){
	if (board.size()>0){
		int m = board.size();
		int n = board[0].size();
		//replace all 'O' with '-'
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (board[i][j]=='O')
					board[i][j] = '-';
			}
		}

		//floddfil for all '-' on edges
		//left and right
		for (int i=0;i<m;i++){
			if (board[i][0] == '-')
				floodFill('-','O',i,0,board);
			if (board[i][n-1] == '-')
				floodFill('-','O',i,n-1,board);
		}
		//top and bottom
		for (int j=0;j<n;j++){
			if (board[0][j] == '-')
				floodFill('-','O',0,j,board);
			if (board[m-1][j] == '-')
				floodFill('-','O',m-1,j,board);
		}

		//filling remaining '-' with 'X'
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (board[i][j]=='-')
					board[i][j] = 'X';
			}
		}

	}
}
void solve(vector <vector <char>> &board){
   fillSurrounded(board); 
    
}
 
};