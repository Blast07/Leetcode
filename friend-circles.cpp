class Solution {
public:
    int find(int i, vector <int> &parent){
        while(parent[i]!=-1)
            i = parent[i];
        return i;
    }
    inline void union_(int i,int j,vector <int> &parent,int &count){
        int par_i = find(i,parent);
        int par_j = find(j,parent);
        if(par_i!=par_j){
            parent[par_j] = par_i;
            count--;
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
       vector <int> parent(M.size(),-1);
       int count = M.size();
       for (int i=0;i<M.size();i++){
          for (int j=i+1;j<M.size();j++){
              if(M[i][j]==1){
                  union_(i,j,parent,count);
              }
          } 
           
       }
       return count;
    }
};