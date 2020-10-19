class Solution {
public:
    int findLength(vector <int> &A, vector <int> &B){
	
	int res  =0;
	for (int i=0;i<A.size();i++){
		for (int j=0;j<A.size();j++){
			int count = 0;
			if (A[i] == B[j]){
				int k = i;
				int x = j;
				while(k<A.size() && j < B.size() && A[k] == B[x]){
					count++;
					k++;
					x++;
				}
				res = max(res, count);
			}
            if (res >= A.size()-i)
                return res;
		
		}
	}
	return res;
}

};