class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int start = 0;
        int end = A.size()-1;
        int mid;
        while(start<=end){
            mid = start + (end-start)/2;
            if (A[mid]>A[mid-1] && A[mid]>A[mid+1]){
                break;//peak
            }
            else if(A[mid]>A[mid-1] && A[mid]<A[mid+1])
                start = mid+1; //left slope
            else 
                end = mid-1;
        }
        return mid;
    }
};