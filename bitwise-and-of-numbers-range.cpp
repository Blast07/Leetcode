class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        if (m==0)
            return 0;
        int ans= m;
        if (m<INT_MAX){
        for (int x=m+1;x<=n && ans;x++){
            ans = ans&x;
            if(x==INT_MAX)
                break;
        }}
        return ans;
    }
};