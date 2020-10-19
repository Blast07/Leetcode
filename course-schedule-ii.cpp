class Solution {
public:
    bool DFS(int cur, vector <vector <int>>&G, vector <int> &visited,vector <int> &res){
        visited[cur]=1;
        for (int i=0;i<G.size();i++){
            if(G[cur][i]==1){
                if(visited[i]==0){
                    if(!DFS(i,G,visited,res))
                       return false; 
                }
                else if(visited[i]==1)
                    return false;
            }
        }
        res.push_back(cur);
        visited[cur] = 2;
        return true;
    } 
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
       vector <vector <int>> G(n,vector <int>(n,0));
       for (auto p:prerequisites)
           G[p[1]][p[0]] = 1;
       vector <int> res;
       vector <int> visited(n,0);
       for (int i=0;i<n;i++){
           if(visited[i]==0){
               if(!DFS(i,G,visited,res))
                   return vector <int>();
           }
       }
       reverse(res.begin(),res.end());
       return res; 
    }
};