class Solution {
public:
    void dfs(int i, int &n, vector <bool> &occupied, int &res){
    
        if (i==n+1){
            res++;
        }else{
            for (int x=1;x<=n;x++){
                if (!occupied[x] && (i%x == 0 || x%i == 0) ){
                    occupied[x] = true;
                    dfs(i+1, n, occupied, res);
                    occupied[x] = false;
                }
            }
        }
    
        return;
    }
    
    int countArrangement(int N) {
    
        vector <bool> occupied(N+1, false);	
        int res = 0;
        dfs(1, N, occupied, res);
    
        return res;
        
    }

};