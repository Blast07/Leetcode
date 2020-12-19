//1027

int longestArithSeqLength(vector<int>& A) {
	int n = A.size();
	int m = *max_element(A.begin(), A.end());
	m++;

	vector <vector<int>>  posD(n, vector <int> (m,1)); 
	vector <vector<int>>  negD(n, vector <int> (m,1)); 

	int res = 1;

	for (int i=1;i<n;i++){
		for (int j=0;j<i;j++){
			int d = A[i] - A[j];
			if(d>=0){
				posD[i][d] = max(posD[i][d], posD[j][d]+1);
			}else{
				d = abs(d);
				negD[i][d] = max(negD[i][d], negD[j][d]+1);
			}

			res = max({res, posD[i][d], negD[i][d]});
		}
	}

	return res;
	
}
