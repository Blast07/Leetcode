class Solution {
public:
    int divide(int dividend, int divisor){
        long int res = 0, D = abs(dividend), d = abs(divisor);
        if (d == 1){
            res = D;
        }else{
            while(1){
                D -= d;	
                if (D >= 0){
                    if (res == INT_MAX){
                        break;
                    }
                    res++;
                }
                else
                    break;
            }
        }
        if ((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0)){
            if (res > INT_MAX)
                res = INT_MAX;
            return res;
        }
        else{
            if (dividend == INT_MIN && res == INT_MAX)
                res++;
            return -res;
        }
    }

};