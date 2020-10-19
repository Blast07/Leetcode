class Solution {
public:
    int find(int i,map <int,int> &parent){
        if(parent.find(i)==parent.end()){
            parent[i] = -1;
            return i;
        }
        while(parent[i]!=-1)
            i= parent[i];
        return i;
            
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map <int,int> parent;
        parent[1] = -1;
        for (auto edge:edges){
           int par_u = find(edge[0],parent);
           int par_v = find(edge[1],parent);
           if (par_u!=par_v)
               parent[par_v] = par_u;
           else
               return edge;
        }
        
        return vector<int>();
    } 
};