class Solution {
public:
    int count;
    int find(int i , vector <int> &parent){
        while(parent[i]!=-1)
            i = parent[i];
        return i;
    }
    void union_(int i,int j, vector <int> &parent){
        int par_i = find(i,parent);
        int par_j = find(j,parent);
        if (par_i!=par_j){
            parent[par_j] = par_i;
            count--; 
        }
        
    }
    int removeStones(vector<vector<int>>& stones) {
        vector <int> parent(stones.size(),-1);
        count = stones.size();
        for (int i=0;i<stones.size();i++){
            for (int j=i+1;j<stones.size();j++){
               if (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                   union_(i,j,parent);
               }     
            }
        }
        return stones.size()-count;
    }
    
};