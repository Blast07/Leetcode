class Solution {
public:
int numIslands(vector <vector <char>> &grid){
	if (grid.size()==0)
        return 0;
    int m = grid.size();
	int n = grid[0].size();
	bool visited[m][n] = {false};
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++)
            visited[i][j] = false;
    } 
	int count = 0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (!visited[i][j] && grid[i][j]=='1'){
				bool bfs = true;
				visited[i][j] = true;
				queue <pair <int,int>>q;
				q.push(make_pair(i,j));
				while(!q.empty()){
					pair <int,int> front = q.front();
					q.pop();
					int cur_i = front.first;
					int cur_j = front.second;
					if ((cur_i-1>=0 && cur_i-1<m) && (!visited[cur_i-1][cur_j] && grid[cur_i-1][cur_j]=='1')){
						q.push(make_pair(cur_i-1,cur_j));
						visited[cur_i-1][cur_j] = true;
					}
					if ((cur_i+1>=0 && cur_i+1<m) && (!visited[cur_i+1][cur_j] && grid[cur_i+1][cur_j]=='1')){
						q.push(make_pair(cur_i+1,cur_j));
						visited[cur_i+1][cur_j] = true;
					}
					if ((cur_j-1>=0 && cur_j-1<n) && (!visited[cur_i][cur_j-1] && grid[cur_i][cur_j-1]=='1')){
						q.push(make_pair(cur_i,cur_j-1));
						visited[cur_i][cur_j-1] = true;
					}
					if ((cur_j+1>=0 && cur_j+1<n) && (!visited[cur_i][cur_j+1] && grid[cur_i][cur_j+1]=='1')){
						q.push(make_pair(cur_i,cur_j+1));
						visited[cur_i][cur_j+1] = true;
					}
				}
				count++;
			}
		}
	}
	return count;
}


};