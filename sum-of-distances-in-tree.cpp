class Solution {
public: 
    

int bottomUp(map <int,vector<int>> &tree,vector <int> &ans,vector <int> &n,int i,vector <bool> &visited ){
    
    visited[i] = 1;
    if (tree.find(i)==tree.end()){
        //no child
        n[i] =1;
        return 1;
    }else {
        for (auto child:tree[i]){
            if (!visited[child]){
            int val = bottomUp(tree,ans,n,child,visited);
            ans[i]+= val+ans[child];
            n[i]+=val;}
        }
        n[i]++;
        return n[i];
    }
    
}

void topDown(map<int,vector<int>> &tree, vector <int> &ans, vector <int> &n,int i,int par,vector <bool> &visited){
    if (!visited[i]){
    visited[i] = 1;
    if(par!=-1)
        ans[i] += (ans.size()-n[i])+(ans[par]-ans[i]-n[i]);
        
    for (auto child:tree[i])
        topDown(tree,ans,n,child,i, visited);
        
    }
    
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges)    {
    map <int,vector<int>> tree;
    vector <int> ans(N,0);
    vector <int> n(N,0);
    vector <bool> visited(N,false);
    
    
    int root=0;
    for (int i=0;i<edges.size();i++){
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
        
        
    }
    
    
    //first traversal
    bottomUp(tree,ans,n,0,visited);
    visited.assign(N,false);
    //second traversal
    topDown(tree,ans,n,0,-1,visited);
    
    return ans;
        
}
};