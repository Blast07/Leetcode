class Solution {
public:
    bool DFS(vector <vector <char>> board,bool **visited,int i,int j,string &word,int cur_char){
        if (!visited[i][j]){
            visited[i][j] = true;
            if (board[i][j] != word[cur_char]){
                visited[i][j] = false;
                return false;
            }
            else{
				if (cur_char==word.size()-1)
					return true;
                if ((i-1>=0 && !visited[i-1][j]) && DFS(board,visited,i-1,j,word,cur_char+1))
                    return true;
                if ((i+1<board.size() && !visited[i+1][j])&& DFS(board,visited,i+1,j,word,cur_char+1))
                    return true;
                if ((j-1>=0 && !visited[i][j-1]) && DFS(board,visited,i,j-1,word,cur_char+1))
                    return true;
                if ((j+1<board[0].size() && !visited[i][j+1]) && DFS(board,visited,i,j+1,word,cur_char+1))
                    return true;
        }
        }
        
        visited[i][j] = false;
        return false;
 } 
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
		int m = board[0].size();
        bool **visited = new bool*[n];
        for (int i=0;i<n;i++){
            visited[i] = new bool[m];
            for (int j=0;j<m;j++)
                visited[i][j] = false;
        }
        
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
               if (board[i][j] == word[0]){
                   if ( DFS(board,visited,i,j,word,0) )
                       return true;
               } 
            }
        }
        return false;
        
    }
};