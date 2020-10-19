#define ll  long long 
class Solution {
public:
    
    bool bs(ll l, ll r, int K ){
        if (l > r)
            return 0;
        ll mid = l+(r-l)/2;
        ll five = 5;
        int count = 0;
        while(five <= mid){
            count += mid/five;	
            five *= 5;
        }
        if (count == K)
            return true;
        else if (count > K)
            return bs(l, mid-1, K);
    
        return bs(mid+1, r, K);
    
    }
    
    int preimageSizeFZF(int K) {
        //answer will always be 5 or 0
        if (bs(0,1e10, K))
            return 5;
        else
            return 0;
    }

};