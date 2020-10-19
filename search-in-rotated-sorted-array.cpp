class Solution {
public:
    

int search(vector<int>& arr, int target) {
    
    int first =0;
    int last =arr.size()-1;
    int mid;
    while(first<=last){
        mid = (first+last)/2;
        if (arr[mid]==target)
            return mid;
        else if(arr[mid]<=arr[last]){
            if(target>arr[mid] && target<=arr[last])
            first=mid+1;
            else
                last=mid-1;
        }else {
            if(target>=arr[first]&&target<arr[mid])
                last = mid-1;
            else 
                first=mid+1;
        }
    }
    return -1;
}

};