class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
	vector <vector <int>> res;
	int i=0,j=0;

	while(i<A.size() && j<B.size()){
		if (A[i][1] >= B[j][0] && B[j][0]>=A[i][0]){// (2,5) (3,7)
			res.push_back({max(B[j][0],A[i][0]), min(B[j][1],A[i][1])});
		}else if(B[j][1] >= A[i][0] && A[i][0] >= B[j][0]){
			res.push_back({max(B[j][0],A[i][0]) , min(B[j][1],A[i][1])});
			
		}

			//increment
			if(B[j][1] == A[i][1]){
				i++;j++;
			}else if(B[j][1] > A[i][1]){
				i++;
			}else
				j++;
		
	}
	return res;
    
}

};