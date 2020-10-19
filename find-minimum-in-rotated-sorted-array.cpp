class Solution {
public:
    int findMin(vector<int>& A) {
        
        if (A.size()==1)
            return A[0];
        else if(A.size()==2)
            return A[0] < A[1] ? A[0]:A[1];
        int start = 0;
        int end = A.size()-1;
        int res;
        int min_ = A[0];
        int max_ = A[end];
        while(start <= end){
            int mid = start + (end - start)/2;
            if (mid+1<=A.size()-1 && A[mid] > A[mid+1]){
                res = mid+1;
                break;
            }
            else if (mid-1>=0 &&A[mid] < A[mid-1]){
                res = mid;
                break;
            }
            if (A[mid] > max_)
                start = mid+1;
            else end = mid-1;
                
        }
        if (A[0]<A[res])
            return A[0];
        return A[res];
    }
};