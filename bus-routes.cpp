class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S==T)
            return 0;
        unordered_map <int,vector <int>> stops;
        queue <int> q;
        vector <int> visited(routes.size(),0); //0 not visited
        for (int i=0;i<routes.size();i++){
            for (int j=0;j<routes[i].size();j++){
                int s = routes[i][j];
                stops[s].push_back(i);
            }
        }
       
        for (int i=0;i<stops[S].size();i++){
            if (!visited[stops[S][i]]){
                visited[stops[S][i]] = 1;
                q.push(stops[S][i]);
            }
        }
        
        while(!q.empty()){
            int front_bus = q.front(); q.pop();
            for (int i=0;i<routes[front_bus].size();i++){
                if (routes[front_bus][i] == T)
                    return visited[front_bus];
            }
            
            for(int i=0;i<routes[front_bus].size();i++){
                //ith stop in route of this bus
                int s = routes[front_bus][i];
                for (int j=0;j<stops[s].size();j++){
                    //jth bus on this stop
                    int b = stops[s][j];
                    if (visited[b]==0){//not visited
                        q.push(b);
                        visited[b] = visited[front_bus]+1;
                    }
                }
            }
        }
        
        return -1;
    }
};