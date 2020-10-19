class Solution {
public:
    void flipPancake(vector <int> &A, int k){
	for (int i=0, r=k-1;i<r;i++,r--)
		swap(A[i], A[r]);		
}

vector<int> pancakeSort(vector<int>& A) {
	vector <int> flips;
	int n = A.size();
    bool no_flip;
	for (int i=n;i>=1;i--){
		no_flip = false;	
		for (int j=i-1;j>=0;j--){
			if(A[j] == i){
				if (j+1 == i){
					break; //no flip required
				}
				if(j>0){
					flips.push_back(j+1);
					flipPancake(A, j+1);
				}
				flips.push_back(i);
				flipPancake(A, i);


			}
		}
	}
	return flips;
}

};