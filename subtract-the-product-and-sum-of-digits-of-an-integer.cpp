class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod =1;
        int sum = 0;
        while(n){
            int rem = n%10;
            n = n/10;
            prod*=rem;
            sum+=rem;
        }
        return prod-sum;
    }
};