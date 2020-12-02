//997

int findJudge(int N, vector<vector<int>>& trust) {
	N++;
	vector <int> trusts(N,0);
	vector <int> trusted_by(N,0);

	for (auto t:trust){
		trusts[t[0]]++;
		trusted_by[t[1]]++;
	}

	for (int i=1;i<N;i++){
		if (!trusts[i] && trusted_by[i] == N-2)
			return i;
	}

	return -1;
}
