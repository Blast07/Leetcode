//1334

//floyd-warshall algo
int findTheCity(int n, vector<vector<int>>& edges, int dt) {
	const int MAX = 10001;
	vector <vector <int>> G(n, vector <int>(n, MAX));

	for (auto edge:edges){
		G[edge[0]][edge[1]] = edge[2];
		G[edge[1]][edge[0]] = edge[2];


	}

	for (int k=0;k<n;k++){
		for (int i=0;i<n;i++){
			for (int j = 0;j<n;j++){
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
	int res;
	int min_ = 101; //n<=100
	for (int i=0;i<n;i++){
        G[i][i] = 0;
		int val = 0;
		for (int j = 0;j<n;j++){
            //cout<<G[i][j]<<" ";
			if (G[i][j] <= dt){
				val++;	
			}
		}//cout<<endl;
        
		if (val <= min_){
			res =i;
			min_ = val;
		}
	}

	return res;

}

/*
//djkastra with adjaceny list
//accepted but slower than warhsall-floyd
int findTheCity(int n, vector<vector<int>>& edges, int dt) {
    dt = -dt;
	vector <int> count(n, 0);
	vector <vector <pair <int,int>>> G(n);

	for (auto edge:edges){
		//G[edge[0]][edge[1]] = -edge[2];
		//G[edge[1]][edge[0]] = -edge[2];
        G[edge[0]].push_back({-edge[2], edge[1]});
        G[edge[1]].push_back({-edge[2], edge[0]});
	}

	for (int i=0;i<n;i++){
		vector <int> visited(n, false);
		priority_queue <pair <int, int>> pq;

		pq.push({0, i});
		//visited[i] = true;

		while(!pq.empty()){
			auto top = pq.top(); pq.pop();
            
            
            if (!visited[top.second]){                
                count[i]++;
                visited[top.second] = true;
            }else
                continue;

            for (auto p:G[top.second]){
                //int u = top.second;
                //int w = top.first;
                if (!visited[p.second]){
                    int dist = top.first + p.first;
                    if (dist >= dt){
                        pq.push({dist, p.second});
                    }
                }
            }
		}
	}
	int val = INT_MAX;
	int res;
	for (int i=0;i<n;i++ ){
        cout<<count[i]<<endl;
		if (count[i] <= val){
			res = i;
			val = count[i];
		}	
	}
	
	return res;
}

//djkastra with adjacency matrix
//accepted but slowest
int findTheCity(int n, vector<vector<int>>& edges, int dt) {
    dt = -dt;
	vector <int> count(n, 0);
	vector <vector  <int>> G(n, vector <int> (n, 0));

	for (auto edge:edges){
		G[edge[0]][edge[1]] = -edge[2];
		G[edge[1]][edge[0]] = -edge[2];
	}

	for (int i=0;i<n;i++){
		vector <int> visited(n, false);
		priority_queue <pair <int, int>> pq;

		pq.push({0, i});

		while(!pq.empty()){
			auto top = pq.top(); pq.pop();
            
            
            if (!visited[top.second]){                
                count[i]++;
                visited[top.second] = true;
            }else
                continue;

			for (int j=0;j<n;j++){
				int u = top.second;
				int w = top.first;

				if (!visited[j] && G[u][j]){
                    
					int dist = G[u][j] + w; 
                    
					if (dist >= dt){
						pq.push({dist, j});
					}
				}
			}
		}
	}
	int val = INT_MAX;
	int res;
	for (int i=0;i<n;i++ ){
        cout<<count[i]<<endl;
		if (count[i] <= val){
			res = i;
			val = count[i];
		}	
	}
	
	return res;
}
*/
