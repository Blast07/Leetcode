class Solution {
public:
    int numberRep(vector <vector <int>> &board){
        int num=0;
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                num = 10*num+board[i][j];
            }
        }
        return num;
    }
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void getAdjacentnodes(queue <int> &q,map <int,int> &visited,int front){
        vector <vector <int>> board(2,vector <int>(3,0));
        int temp = front;
        //getting original board back
        int x,y;
        for (int i=1;i>=0;i--){
            for (int j=2;j>=0;j--){
                board[i][j] = temp%10;
                if (board[i][j]==0){
                    x=i;
                    y=j;
                }
                temp = temp/10;
            }
        }
        if (x-1>=0){
            swap(board[x-1][y],board[x][y]);
            if (visited.find(numberRep(board))==visited.end()){
                q.push(numberRep(board));
                visited[numberRep(board)] = visited[front]+1;
            }
            swap(board[x-1][y],board[x][y]);
        } 
        
        if (x+1<2){
            swap(board[x+1][y],board[x][y]);
            if (visited.find(numberRep(board))==visited.end()){
                q.push(numberRep(board));
                visited[numberRep(board)] = visited[front]+1;
            }
            
            swap(board[x+1][y],board[x][y]);
        } 
        if (y-1>=0){
            
            swap(board[x][y-1],board[x][y]);
            if (visited.find(numberRep(board))==visited.end()){
                q.push(numberRep(board));
                visited[numberRep(board)] = visited[front]+1;
            }
            swap(board[x][y-1],board[x][y]);
        } 
        if (y+1<3){
            swap(board[x][y+1],board[x][y]);
            if (visited.find(numberRep(board))==visited.end()){
                q.push(numberRep(board));
                visited[numberRep(board)] = visited[front]+1;
            }
            swap(board[x][y+1],board[x][y]);
        } 
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        map <int,int> visited;
        queue <int> q;
        visited[numberRep(board)] = 0;
        q.push(numberRep(board));
        int dest = 123450;
        while(!q.empty()){
            int front = q.front(); q.pop();
            if (front == dest)
                return visited[front];
            getAdjacentnodes(q,visited,front);
            
        }
        
        
        return -1;
        
    }
};