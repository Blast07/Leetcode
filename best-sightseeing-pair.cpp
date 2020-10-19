class Solution {
public:
int maxScoreSightseeingPair(vector <int> &A){
	int res = 0;
	int max_ht = A[0];

	for (int i=1;i<A.size();i++){
		max_ht--;	
		res = max(res, max_ht+A[i]);
		max_ht = max(max_ht, A[i]);
	}
	return res;

}

};