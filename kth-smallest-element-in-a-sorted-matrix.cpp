class Solution {
public:
bool isValid(vector<vector <int>> &matrix, int mid, int k  ){
	int count = 0;

	for (int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix.size();j++){
			if (matrix[i][j] <=  mid)
				count++;
		}
	}
	return count < k;
}

int kthSmallest(vector <vector <int>> &matrix, int k){

	int n = matrix.size();

	if (n == 0 && k>n)
		return 0;
		
	int low = matrix[0][0];	
	int high = matrix[n-1][n-1];

	while(low<high){
		int mid = low + (high - low)/2;
		if (isValid(matrix, mid, k)){
			low = mid+1;
		}else
			high = mid;
	}

	return high;
}

};