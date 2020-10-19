class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size()-1;
        if (e==-1)
            return false;
        while(s<=e){
            int m = s + (e-s)/2;
            if (target == arr[m])
                return true;
            else if(arr[m]==arr[s] && arr[m]==arr[e])
                e--;
            else if(arr[m]>=arr[s]){
                //in 1st part
                if (target >= arr[s] && target <= arr[m])
                    e = m-1;
                else
                    s = m + 1;
            }else if(arr[m] <= arr[e]){
                //2nd part
                if (target >= arr[m] && target <= arr[e])
                    s = m+1;
                else
                    e = m-1;
            }
            
        }
        return false;
    }
};