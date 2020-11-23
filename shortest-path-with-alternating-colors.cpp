//1129

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
	vector <vector <vector <int>>> G(n, vector <vector <int>>(2));
	//G[i][0] = {red_edges}
	//G[i][1] = {blue_edges}
	for (auto red:red_edges){
		G[red[0]][0].push_back(red[1]);	
	}

	for (auto blue:blue_edges){
		G[blue[0]][1].push_back(blue[1]);	
	}

	vector < vector<bool>> visited(n, vector <bool>(2, false));
	visited[0][0] = true;
	visited[0][1] = true;

	vector <int> res(n,-1);
	

	queue <vector <int>> q;
	for (int j:G[0][0]){
		q.push({j, 0, 1}); //{vertex, color, distance}
		visited[j][0] = true;
		res[j] = 1;
	}
	
	for (int j:G[0][1]){
		q.push({j, 1, 1}); //{vertex, color, distance}
		visited[j][1] = true;
		res[j] = 1;
	}
    
    res[0] = 0;
    
	while(!q.empty()){
		auto front = q.front(); q.pop(); 	

		int i = front[0];
		int c = front[1];
		int d = front[2];

		for (int j:G[i][!c]){
			if (!visited[j][!c]){

				visited[j][!c] = true;
				q.push({j, !c, d+1});

				if (res[j] == -1)
					res[j] = d+1;
			}
		}
	
	}

	return res;
}
