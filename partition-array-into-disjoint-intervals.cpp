class Solution {
public:
 int partitionDisjoint(vector<int>& A) {
	int res = 0;	        
	vector <int> left; //largest till i from left
	vector <int> right(A.size()); //smallest element till i from right

	left.push_back(A[0]);
	for (int i=1;i<A.size();i++){
		left.push_back(max(left[i-1], A[i]));
	}

	right[A.size()-1] = A.back();

	for (int i = A.size()-2;i>=0;i--){
		right[i] = min(right[i+1], A[i]);
	}
	for (int i=0;i<A.size()-1;i++){
		if (left[i] <= right[i+1])
			return i+1;
	}

	return 0; //dummy return, control will not reach here
}



};