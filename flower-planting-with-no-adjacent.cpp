//1042

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
	//graph coloring, with 4 colors    
	vector <vector <int>> adj(n);
	vector <vector <bool>> color_avail(n, vector <bool>(5,true)); // 1,2,3,4
	
	for (auto p:paths){
		adj[p[0]-1].push_back(p[1]-1);
		adj[p[1]-1].push_back(p[0]-1);
	}

	vector <int> res(n, 0);
	vector <bool> visited(n, false);

	for (int i=0;i<n;i++){
		if (!visited[i]){
			vector <int> st;
			st.push_back(i);
            
			visited[i] = true;

			while(!st.empty()){
                
				int top = st.back(); st.pop_back();
                
				int c;
				for (c=1;c<5;c++){
					if (color_avail[top][c]){
						res[top] = c;
						break;
					}	
				}

				for (int j:adj[top]){
					color_avail[j][c] = false; 
					if (!visited[j]){
						st.push_back(j);
						visited[j] = true;
					}
				}
			}

		}	
	}

	return res;

}
