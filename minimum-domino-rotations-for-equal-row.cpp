class Solution {
public:
  vector <int> majorityElement(vector <int> &arr){
	int count = 1;
	int maj = arr[0];
	for (int i=1;i<arr.size();i++){
		if (arr[i]==maj){
			count++;
		}else{
			count--;
		}
		if (count==0){
			maj = arr[i];
			count = 1;
		}
	}
	count = 0;
	for (int i=0;i<arr.size();i++){
		if (arr[i] == maj)
			count++;
	}
	if (count<arr.size()/2)
		return {-1};

	return {maj,count};
}
int minDominoRotations(vector<int>& A, vector<int>& B) {
	int n = A.size();

	vector <int> mA = majorityElement(A);
	vector <int> mB = majorityElement(B);
	if (mA[0] == -1 && mB[0] == -1)
		return -1;  
	else if (mA[0] == -1){
		for (int i=0;i<B.size();i++){
			if (!(A[i] == mB[0] || B[i] == mB[0]))
				return -1;
		}
		return B.size() - mB[1];
	}else if (mB[0] == -1){
	
		for (int i=0;i<A.size();i++){
			if (!(B[i] == mA[0] || A[i] == mA[0]))
				return -1;
		}
		return A.size() - mA[1];
		
	}else{
		int ans = INT_MAX, i;
		for (i = 0;i<A.size();i++){
			if (!(B[i] == mA[0] || A[i] == mA[0]))
				break;	
		}
		if (i==A.size()){
			ans  = A.size() - mA[1];
		}

		for (i=0;i<B.size();i++){
			if (!(A[i] == mB[0] || B[i] == mB[0]))
				break;
		}
		
		if (i == B.size()){
            if (B.size() - mB[1] < ans)
                ans = B.size() - mB[1];
			
		}
        if (ans == INT_MAX)
            return -1;
		return ans;
	}

}

};