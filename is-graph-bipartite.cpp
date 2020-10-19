class Solution {
public:
    
    bool BFS(vector <vector <int>> &graph,vector <int>&visited, int i){
        queue <int> q;
        q.push(i);
        visited[i] = 1; //color1
        int same_color = 1;
        int opposite_color = 2;
        while(!q.empty()){
            int l = q.size();
            int j = 0;
            while(j<l){
                int front = q.front();q.pop();
                
                
                for (int k=0; k<graph[front].size() ;k++){
                    int node = graph[front][k];
                    
                    if (!visited[node]){
                        q.push(node);
                        visited[node] = opposite_color;
                    }else if(visited[node]==same_color)
                        return false;
                    
                }
                j++;
            }
            swap(same_color,opposite_color);
        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> visited(graph.size(),0);
        
        
        for (int i=0;i<n;i++){
            if (!visited[i] && !BFS(graph, visited, i)){
                return false;
            }    
        }
        return true;
    }
    
    
};