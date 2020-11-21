//802

bool dfs(int i, vector <vector<int>> &graph, vector <int> &labels){
	labels[i] = 1; //being explored

	for (int j : graph[i]){
		if ((labels[j] == 1 || labels[j] == 2) || (labels[j] == 0 && !dfs(j, graph, labels))){
			labels[i] = 2; //not safe
			return false;
		}
	}
	labels[i] = 3; //safe state
	return true;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	int n = graph.size();
	vector <int> labels(n,0);	
	//labels
	//0- not visited
	//1- being explored
	//2- not safe
	//3- safe state

	//a node is safe if it is a terminal, or all of its children lead
	//to terminal no mater what path you follow

	vector <int> res;
	for (int i=0;i<n;i++){
		if (labels[i] == 0){
			dfs(i, graph, labels);
		}

		if(labels[i] == 3){
			res.push_back(i);
		}
	}
    return res;
}
