//1439

int kthSmallest(vector<vector<int>>& mat, int k) {
	int m = mat.size(), n = mat[0].size();
	multiset <pair <int, vector <int>>> s;

	vector <int> smallest(m, 0);
	int sum = 0;
	for (int i=0;i<m;i++){
		sum += mat[i][0];
	}

	s.insert({sum, smallest});
	int cur  = 0;
	set <vector <int>> visited;


	while(!s.empty()){
		pair <int, vector <int>> p = *(s.begin());
		s.erase(p);

		cur++;

		if (cur == k)
			return p.first; //return kth smallest sum

		//generate candidates
		vector <int> candidate = p.second;
		int sum  = p.first;
		for (int i=0;i<m;i++){

			candidate[i]++;
			if (candidate[i] < n && visited.find(candidate) == visited.end()){
				sum -= mat[i][candidate[i]-1];
				sum += mat[i][candidate[i]];	

				s.insert({sum, candidate});

				sum -= mat[i][candidate[i]];
				sum += mat[i][candidate[i]-1];
			}
			candidate[i]--;
		}
	}
	return 0; //dummy return
}
