//59

vector<vector<int>> generateMatrix(int n) {
	vector <vector <int>> matrix(n, vector <int> (n,0));	    

	int u = 0, r = n-1, d = n-1, l = 0;
	
	int cur = 1;
	while(u<=d && l <=r){
		for (int i=l;i<=r;i++){
			matrix[u][i] = cur++;	
		}
		u++;

		for (int i=u;i<=d;i++){
			matrix[i][r] = cur++;
		}
		r--;

		for (int i=r;i>=l;i--){
			matrix[d][i] = cur++;
		}
		d--;

		for (int i=d;i>=u;i--){
			matrix[i][l] = cur++;
		}
		l++;
	}

	return matrix;
}
