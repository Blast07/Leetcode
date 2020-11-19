//1514

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
  	
	vector <vector <pair <double,int>>> G(n);

	//adjacency list 
	for (int i=0;i<edges.size();i++){
		G[edges[i][0]].push_back({succProb[i], edges[i][1]});
		G[edges[i][1]].push_back({succProb[i], edges[i][0]});

	}

	vector <bool> visited(n, false);
	vector <double> dist(n, 0);
	priority_queue <pair<double, int>> pq;

	
	pq.push({0, start});
	dist[start] = 1; //probability is 1, as we are already on this node

	while(!pq.empty()){
		auto top = pq.top(); pq.pop();
        
		if (visited[top.second])
			continue;
		visited[top.second] = true;
        //cout<<top.second<<endl;
		for (auto p : G[top.second]){
			int u = top.second;
			if (p.first*dist[u] > dist[p.second]){
				dist[p.second] = p.first*dist[u];
                pq.push({dist[p.second], p.second});
			}
		}
	}
	return dist[end]; 
}
