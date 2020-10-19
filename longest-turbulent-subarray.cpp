class Solution {
public:
int maxTurbulenceSize(std::vector<int>& A) {
    
	int i = 0;
	int res = 0;
	
	while(i<A.size()){
		int j = i;
		while(j+1 < A.size() && A[j]==A[j+1]){
			j++;
		}
		i = j;
		bool flag;
		if (j+1<A.size()){
			flag = A[j] < A[j+1];
            j++;
        }else{
            res = max(res,1);
            break;
        }

		while(j+1 < A.size()){
            if (A[j] == A[j+1])
                break;
            if (A[j] < A[j+1] == !flag){
			    j++;
			    flag = !flag;
            }else
                break;
		}

		res = max(res, j-i+1);
        i = j;
	}
    
	return res;
}


};