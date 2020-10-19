class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i= 0;
        int j =arr.size()-1;
        int m=0;
        while(i<j){
            int mi = min(arr[i], arr[j]);
            m = max(m, (j-i)*mi);
            int left = min(arr[i+1], arr[j]);
            int right = min(arr[i], arr[j-1]);
            
            if (left >mi || right>mi){
                if (left>right)
                    i++;
                else j--;
            }else {
                if (arr[i]>arr[j])
                    j--;
                else 
                    i++;
            }
            
        }
        return m;
}
    
    };