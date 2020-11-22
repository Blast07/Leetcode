//1615

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
	vector <int> rank(n, 0);
	vector <vector <int>> graph(n, vector <int> (n, 0));

	for (auto road:roads){
		rank[road[0]]++;
		rank[road[1]]++;

		graph[road[0]][road[1]] = 1; 
		graph[road[1]][road[0]] = 1; 
	}
	int res =0;

	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			int count = rank[i] + rank[j];	
			if (graph[i][j])
				count--;
			res = max(res, count);
		}
	}

	return res;
}
