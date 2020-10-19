class Solution {
public:
  std::vector <int> advantageCount(std::vector <int> &A, std::vector <int> &B){	
	std::vector <int> res(A.size());
	std::vector <int> indices_left;
	std::vector <int> zeros;
	sort(A.begin(), A.end());

	for (int i=0;i<B.size();i++){
		//binary search
		int l = 0;
		int r = A.size()-1;
        if (B[i]==0){
           zeros.push_back(i); 
            continue;
        }
		while(l<=r){
			int m = (l + r)/2;
			if (abs(A[m]) > B[i]){
				if (l==r && A[m]>0) {
					res[i] = A[m];
					A[m]*=-1;
					break;
				}else if (A[m]<0){
                    if(A[l]<=B[i]) 
					    l++;
                    else
                        r = m-1;
				}else{
					r = m;
				}
					
			}else{
				l = m+1;
			}
		}
		if (l>r){
			indices_left.push_back(i);
		}
	}

	for (int i=0;i<A.size();i++){
		if (A[i]>0 && zeros.size()>0){
			res[zeros.back()] = A[i];
			zeros.pop_back();
            A[i]*=-1;
		}
	}
    for (int i=0;i<A.size();i++){
        if (A[i]>0 && indices_left.size() > 0){
            res[indices_left.back()] = A[i];
			indices_left.pop_back();
        }
        
    }
      

	return res;
}

};