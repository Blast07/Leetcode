//1631

int minimumEffortPath(vector<vector<int>>& heights) {

	int r = heights.size();
	int c = heights[0].size();
    if (r==1 && c==1)
        return 0;
	
	vector <vector <bool>> vis(r,vector <bool>(c, false));

	priority_queue <pair <int, pair<int, int>>> pq;
	pq.push({0, {0,0}});

	vector <vector<int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};

	while(!pq.empty()){
		auto top = pq.top(); pq.pop();

		int x = top.second.first;
		int y = top.second.second;
		
		if (x == r-1 && y == c-1)
			return -top.first;
		if (vis[x][y])
			continue;

		vis[x][y] = true;

		for (auto d:dir){
			int x_ = x + d[0];
			int y_ = y + d[1];

			if (x_ >= 0 && x_ < r && y_ >= 0 && y_ <c){
				int new_diff = abs(heights[x_][y_] - heights[x][y]);
                
				pq.push({-max(new_diff, -top.first) , {x_,y_}});
			}
		}
	}

	return 0; //dummy return 

}
