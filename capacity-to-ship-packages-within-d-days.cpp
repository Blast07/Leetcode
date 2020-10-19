class Solution {
public:
    
    bool test(vector <int> &weights, int capacity, int D){
        int days_required =0;
        int cur_capacity = capacity;
        
        for (int i=0;i<weights.size();i++){
            if (capacity < weights[i])
                return false;
            if (cur_capacity >= weights[i]){
                cur_capacity -= weights[i];
            }else{
                days_required++;
                cur_capacity = capacity - weights[i];
            }
        }
        days_required++;
        return days_required <= D;
        
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int res = INT_MAX;
        int min_ = 0;
        int max;
        for (int i=0;i<weights.size();i++)
            max+=weights[i];
        
        while(min_<=max){
            int mid = min_ + (max-min_)/2;
            if (test(weights,mid,D)){
                res = min(mid,res);
                max = mid-1;
            }else{
                min_ = mid+1;
            }
        }
        
        return res;
    }
};