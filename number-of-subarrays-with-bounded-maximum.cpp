class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    	int i = 0, first_valid  =0;
	int last_valid = 0;
	int n = A.size();	
	int res = 0;
	while(i < n){
        bool no_valid = true;
		
		while(i < n && A[i]<=R){

			if (A[i] >= L){
                no_valid = false;
				res++;
				last_valid = i;
			    res +=  last_valid  - first_valid;
			}else{
                if (!no_valid)
                    res += last_valid - first_valid + 1;
            }
            i++;
		} 
		first_valid = ++i;
		last_valid = first_valid;

	}
	return res;

    }
};