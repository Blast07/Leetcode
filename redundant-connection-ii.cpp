//685

int find(int a, vector <int> &parent){
	if (a == parent[a])
		return a;
	else{
		parent[a] = find(parent[a], parent);
		return parent[a];
	}
}


vector <int> detectCycle(int n, vector <vector <int>> &edges, vector <int> &skip){
	vector <int> parent(n,0);
	for (int i=1;i<n;i++){
        //cout<<i<<endl;
		parent[i] = i;	
	}
	vector <int> res = {};
    //cout<<"out-loop"<<endl;
	for (auto edge:edges){
        
		if (skip.size() && (skip[0] == edge[0]) && (skip[1] == edge[1])){
			continue;
		}
		int pa =  find(edge[0], parent);
		int pb =  find(edge[1], parent);

		if (pa == pb){
			res = edge;
		}else{
			parent[pb] = parent[pa];
		}
	}

	return res;
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
	unordered_map <int,int> parent;
	vector <int> edge1, edge2;
	int n =0;

	for (auto edge:edges){
		if (parent[edge[1]] == 0){
			parent[edge[1]] = edge[0];
		}else{
			edge1 = edge;
			edge2 = {parent[edge[1]], edge[1]};
		}
		n = max({n, edge[0], edge[1]});
	}
	n++;

	if (edge1.size() == 0){
        vector <int> skip = {};
		return detectCycle(n, edges, skip);	
	}else{
		vector <int> res;
        //cout<<"two"<<endl;
		res = detectCycle(n, edges, edge1);
        
		if (res.size()!=0)
			return edge2;

		return edge1;
	}

}
