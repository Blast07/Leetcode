//1462

vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
	//floyd-warshall
	vector <vector <bool>> G(n, vector <bool>(n, false)); //path matrix
	
	for (auto p:prerequisites){
		G[p[0]][p[1]] = true;
	}

	for (int k=0;k<n;k++){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				G[i][j] = G[i][j] | (G[i][k] && G[k][j]);
			}
		}
	}
	vector <bool> res;
	for (auto q:queries){
		if (G[q[0]][q[1]])
			res.push_back(true);
		else
			res.push_back(false);
	}

	return res;	
}
