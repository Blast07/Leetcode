class Solution {
public:
    pair <int,int> numRep(int tail_x,int tail_y,int head_x,int head_y,int n){
        pair <int,int> p;
        p.first = n*tail_x + tail_y;
        p.second = n*head_x + head_y;
        return p;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        map <pair<int,int>, int> visited;
        queue <pair<int, int>> q;
        q.push(numRep(0,0,0,1,n));
        visited[numRep(0,0,0,1,n)] = 0;
        pair <int,int> dest = numRep(n-1,n-2,n-1,n-1,n);
        while(!q.empty()){
            pair <int,int> front = q.front(); q.pop();
            if (front==dest)
                return visited[front];
     
            int head_x = front.second/n;
            int head_y = front.second%n;
            int tail_x = front.first/n; 
            int tail_y = front.first%n;
            
            //if laying horizontal
            if (head_x==tail_x && tail_y+1 == head_y){
                if (head_y+1 < n && !grid[head_x][head_y+1]){//move right
                    pair <int,int> num = numRep(tail_x,tail_y+1,head_x,head_y+1,n);
                    if(visited.find(num)==visited.end()){
                        q.push(num);
                        visited[num] = visited[front] +1;
                    }
                }
                //rotate clockwise
                if (head_x+1 < n && (!grid[tail_x+1][tail_y] && !grid[head_x+1][head_y])){
                    pair <int,int> num  = numRep(tail_x,tail_y,tail_x+1,tail_y,n);
                    if(visited.find(num)==visited.end()){
                        q.push(num);
                        visited[num] = visited[front] +1;
                    }
                }
                //move down
                if (head_x+1<n && (!grid[head_x+1][head_y] && !grid[tail_x+1][tail_y])){
                    pair <int,int> num = numRep(tail_x+1,tail_y,head_x+1,head_y,n);
                    if(visited.find(num)==visited.end()){
                        q.push(num);
                        visited[num] = visited[front] +1;
                    }
                }
            }
            
           //laying vertical 
           if (tail_y==head_y && tail_x+1 == head_x){
               
               if (head_x+1 <n && !grid[head_x+1][head_y]){//move down
                    pair<int,int> num = numRep(tail_x+1,tail_y,head_x+1,head_y,n);
                    if(visited.find(num)==visited.end()){
                        q.push(num);
                        visited[num] = visited[front] +1;
                    }
               }
               //counter rotation
               if (head_y+1<n && (!grid[head_x][head_y+1] && !grid[tail_x][tail_y+1])){
                   pair<int,int> num = numRep(tail_x,tail_y,tail_x,tail_y+1,n);
                    if(visited.find(num)==visited.end()){
                        q.push(num);
                        visited[num] = visited[front] +1;
                    }
               }
               //move right
               if (head_y+1<n && (!grid[head_x][head_y+1] && !grid[tail_x][tail_y+1])){
                    pair <int,int> num = numRep(tail_x,tail_y+1, head_x,head_y+1,n);
                    if(visited.find(num)==visited.end()){
                        q.push(num);
                        visited[num] = visited[front] +1;
                    }
               }
           }
            
        }
        return -1;
        
    }
};