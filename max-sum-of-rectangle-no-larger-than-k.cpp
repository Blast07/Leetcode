//363

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
	int n = matrix.size();
	int m = matrix[0].size();

	int res = INT_MIN;

	for (int i=0;i<n;i++){
		vector <int> cum(m, 0);
		for (int j=i;j<n;j++){
			for(int y=0;y<m;y++){
				cum[y] += matrix[j][y];
			}

			set <int> acc;
			acc.insert(0);
			int sum = 0;

			for (int x:cum){
				sum += x;
				auto it = acc.lower_bound(sum-k);//first-value >= sum-k
				if (it!-acc.end()){
					res = max(res, sum-*it);
				}
				acc.insert(sum);
			}
		}
	}

	return sum;
}