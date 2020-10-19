class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
	int N = grid.size()-1;
	if (grid[N][N] == (N+1)*(N+1)-1)
		return (N+1)*(N+1)-1;

	unordered_map <int, pair<int,int>> mp;

	for (int i=0;i<=N;i++){
		for (int j=0;j<=N;j++){
			mp[grid[i][j]] = {i, j};
		}
	}

	priority_queue <int, vector <int>, greater<int>> min_heap;
	min_heap.push(grid[0][0]);
    grid[0][0] = -1;
	int res = -1;

	while(min_heap.size()){
		int top = min_heap.top(); min_heap.pop();	
		res = max(res, top);
        
		int x = mp[top].first;
		int y = mp[top].second;

		if (x == N && y == N)
			break;

		if (x + 1 <= N && grid[x+1][y] >= 0){
			min_heap.push(grid[x+1][y]);
			grid[x+1][y] = -1;
		}

		if (y + 1 <= N && grid[x][y+1] >= 0){
			min_heap.push(grid[x][y+1]);
			grid[x][y+1] = -1;
		}
		
        if (y - 1 >=  0 && grid[x][y-1] >= 0){
			min_heap.push(grid[x][y-1]);
			grid[x][y-1] = -1;
		}
        
        if (x - 1 >=  0 && grid[x-1][y] >= 0){
			min_heap.push(grid[x-1][y]);
			grid[x-1][y] = -1;
		}
	}
	return res;
}

};