//310

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
	if (n == 1)
		return {0};
	else if (n == 2)
		return {0, 1};
	
	vector <vector <int>> graph(n);

	for (auto edge:edges){
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}

	vector <int> degrees(n, 0);
	queue <int> q;

	for (int  i = 0;i <n; i++){
		degrees[i] = graph[i].size();
		if (degrees[i] == 1)
			q.push(i);
	}

	vector <int> res;

	while (!q.empty()){
		int n = = q.size();
		res.clear();
		while(n--){
			int node = q.front(); q.pop();
			res.push_back(node);

			for (int x:graph[node]){
				degrees[x]--;
				if (degrees[x] == 1)
					q.push(x);
			}
		}
	}

	return res;
}
