class Solution {
public:
    int arrangeCoins(int n) {
        int res = 0, i = 1;
        while(n >= i){
            res++;
            n -= i++;
        }
        return res;
        
    }
};