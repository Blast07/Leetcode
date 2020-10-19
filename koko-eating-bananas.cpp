class Solution {
public:
    
    bool test(vector <int> piles, int eat_speed, int H){
        int hours = 0;
        for (int i=0;i<piles.size();i++){
           hours += ceil((float)piles[i]/(float)eat_speed); 
        }
        return hours <= H;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int min_ = 1;
        int max_ = INT_MIN;
        for (int i=0;i<piles.size();i++){
            
            if (piles[i] > max_)
                max_ = piles[i];
        }
        
        int res = INT_MAX;
        while(min_ <= max_){
            int mid = min_ + (max_ -min_)/2;
            if (test(piles,mid,H)){
                res = min(res,mid);
                max_ = mid-1;
            }else{
                min_ = mid+1;
            }
        }
        return res;
    }
};