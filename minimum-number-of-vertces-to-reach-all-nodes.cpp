//1557

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
	vector <int> in(n, 0);    

	for (auto edge:edges){
		in[edge[1]]++;
	}

	vector <int> res;

	for (int i=0;i<n;i++){
		if (in[i] == 0)
			res.push_back();
	}

	return res;
}
