class Solution {
public:
    int makeBouqets(vector <int> arr, int m, int k, int mid){
        
        int temp_m = k;
        int boq = 0;
        for (int i=0;i<arr.size();i++){
            if (arr[i] <= mid){
                temp_m--;
                if (temp_m == 0){
                    boq++;
                    temp_m = k;
                }
            }else{
                temp_m = k;
            }
        }
    
        return boq;
    }
    
    int minDays(vector <int> &bloomDay, int m, int k){
    
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int res = -1;
    
        while(l <= r){
            int mid = l + (r-l)/2;
            int boq = makeBouqets(bloomDay, m, k, mid);
            if (boq >= m){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
    
        return res;
    }

};