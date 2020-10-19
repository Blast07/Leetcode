class Solution {
public:
    double f(double x, int n){ //return x^n
        if (n == 0)
            return 1;
        
        double t = f(x, n/2);
        t *=t;
    
        if (n%2)
            t *= x;
    
        return t;
    }
        
    double myPow(double x, int n){ //return x^n
       double res = f(x, n);
       if (n < 0)
           res = (double)1/res;
       return res;
    }
};