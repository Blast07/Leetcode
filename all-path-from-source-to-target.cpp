//797

void dfs(int i,vector <int> &path,vector <vector <int>> &graph, vector<vector<int>> &res){
	path.push_back(i);
	if (i == graph.size()-1){
		//reached n-1
		res.push_back(path);
	}else{
		for (int v:graph[i])
			dfs(v, path, graph, res);	
	}

	path.pop_back(v);
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	
	vector <vector <int>> res;
	vector <int> path;
	dfs(0, path,graph,res);
	return res;

}
