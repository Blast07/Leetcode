class Solution {
public:
 //  https://leetcode.com/problems/2-keys-keyboard/discuss/464391/C%2B%2B-solution-with-explanation 
    map <pair<int,int>,int> mem; 
    int minKeys(int n, int cur, int copy){
        if (cur==n)
              return 0;
        else if (cur==1)
            return 2+minKeys(n,2,1);
        /*
            2 options - either use prev. copy or copy the current A's
        */
        else if(mem.find({cur,copy})!=mem.end())
            return mem[{cur,copy}];
        else if (cur>n)
            return INT_MAX;
        else{
            int using_prev = minKeys(n,cur+copy,copy);
            if (using_prev!=INT_MAX)
                using_prev += 1; //only paste op.
            int using_cur = minKeys(n,cur+cur,cur);
            if (using_cur!=INT_MAX)
                using_cur += 2; //copy and past op
            mem[{cur,copy}]  = min(using_cur,using_prev);
            return mem[{cur,copy}];
        }
            
    }
    int minSteps(int n) {
       mem.clear();
       if (n==1) return 0;
       return minKeys(n,1,0); 
    }
};