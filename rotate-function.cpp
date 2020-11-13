//396

//Rotate: 
//    F(0) = 0A + 1B + 2C +3D
//
//    F(1) = 0D + 1A + 2B +3C
//
//    F(2) = 0C + 1D + 2A +3B
//
//    F(3) = 0B + 1C + 2D +3A
//
//    Pattern: 
//    sum = 1A + 1B + 1C + 1D
//
//    F(1) = F(0) + sum - 4D where 4D = 3D + sum(1D)
//
//    F(2) = F(1) + sum - 4C
//
//    F(3) = F(2) + sum - 4B
//	
//	Formula:
//	F(i) = F(i - 1) + sum - n * A[n - i]

#define ll long long

int maxRotateFunction(vector <int> &A){
	int n = A.size();
	if (n == 0)
		return 0;

	ll sum = 0, f = 0;	
	for (int i=0;i<n;i++){
		sum += A[i];
		f += i*A[i];
	}

	ll res = f;
    
	for (int i=1;i<n;i++){
		f = f + sum - (ll)n*A[n-i];	
		res = max(res, f);
	}
	
	return res;

}

/* O(n^2)
int maxRotateFunction(vector<int>& A) {
	int n = A.size();
	vector <int> sums(n, 0);

	for (int i=0;i<n;i++){
		int k = 0;
		for (int j=i;j<n;j++, k++){
			sums[k] += j*A[i];
		}

		for (int j=0;j<i;j++){
			sums[k] += j*A[i];
		}
	}

	return *max_element(sums.begin(), sums.end());
}
*/
