class Solution {
public:
    bool DFScycle(vector <vector <int>> &G,int v,vector <int> &label){
        if (label[v]==0){//not explored
            label[v]=1;//being explored
            for (int i=0;i<G.size();i++){
                if (G[v][i]!=0){
                    if (label[i]==1)//cycle
                        return true;
                    if (label[i]==0 && DFScycle(G,i,label))
                        return true;
                        
                }
            }
            label[v]=2;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& courses) {
        vector <vector <int>> G(numCourses,vector <int>(numCourses,0));
        for (int i=0;i<courses.size();i++){
            G[courses[i][1]][courses[i][0]] = 1;
        }
        
        //cycle detection
        vector <int> label(numCourses,0);
        for (int i=0;i<numCourses;i++){
            if (DFScycle(G,i,label))
                return false;
        }
        return true;
        
    }
};