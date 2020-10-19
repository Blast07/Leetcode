class Solution {
public:
    int findPeakElement(vector <int> &v){
    if (v.size()==1)
        return 0;
    int low= 0,high = v.size()-1;
    while(low<high){
        int mid = low+(high-low)/2;
        if (v[mid]>v[mid+1])
            high = mid;
        else
            low = mid+1;
        
    }
    return low;}
 
};