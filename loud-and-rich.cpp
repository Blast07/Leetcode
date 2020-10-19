class Solution {
public:
    int loudAndRich(vector <vector<int>> &G,vector <int> &quiet,vector <int> &visited,vector <int>&answer, int i){
        for (int j=0;j<quiet.size();j++){
            if (G[i][j] && !visited[j]){
                int ind = loudAndRich(G,quiet,visited,answer,j);
                if (quiet[ind] < quiet[answer[i]]){
                   answer[i] = ind;
                }
            }else if(G[i][j] && visited[j]){
                if(quiet[answer[j]] < quiet[answer[i]])
                    answer[i] = answer[j];
            }
        }
        visited[i] = true;
        return answer[i];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector <int> answer(quiet.size(), 0);
        for (int i=0;i<quiet.size();i++){
            answer[i] = i;
        } 
        vector <vector <int>> G(quiet.size(), vector <int>(quiet.size(),0));
        vector <int> visited(quiet.size(),false);
        
        for (int i=0;i<richer.size();i++){
            G[richer[i][1]][richer[i][0]] = 1;
        }
        
        for (int i=0;i<quiet.size();i++){
            if(!visited[i]){
                for (int j=0;j<quiet.size();j++){
                    if(G[i][j] && !visited[j]){
                        int ind = loudAndRich(G,quiet,visited,answer,j);
                        if (quiet[ind] < quiet[answer[i]]){
                            answer[i] = ind;
                        }
                    }
                    else if(G[i][j] && visited[j]){
                        if(quiet[answer[j]] < quiet[answer[i]])
                        answer[i] = answer[j];
                    }
                }
                visited[i] = true;
            }
        }
        return answer;
    }
};
    
    