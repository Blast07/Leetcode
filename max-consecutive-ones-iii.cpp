class Solution {
public:
int longestOnes(vector<int>& A, int K) {
    int res =0 ;
    int start = 0;
    int end = 0;
    int countk = K;
    while(end < A.size()){
        if (A[end] == 1){
            //
        }else{
            if(countk >0)
                countk--;
            else{
                //pending
                while(A[start]==1){
                    start++;
                }
                start++;
                
            }
            
            
        }
        res =max(res, end-start+1);
        end++;
    }
    return res;
}


};