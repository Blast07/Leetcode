class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map <string,map<string,int>> m;
        for (int i=0;i<tickets.size();i++)
           m[tickets[i][0]][tickets[i][1]]++;
        
        vector <string> res;
        DFS("JFK","",m,res); 
        return res;
    }
    
    bool DFS(string cur,string par, map<string, map<string,int>> &m, vector <string>&res){
       res.push_back(cur);
       if(m.find(cur)==m.end()){
          for(auto i=m.begin();i!=m.end();i++){
            for (auto j=i->second.begin() ;j!= i->second.end();j++){
                if (j->second!=0){
                    res.pop_back();
                    return false;
                }
                    
            }
          } 
          return true;
       }else{
           for (auto i = m[cur].begin();i!=m[cur].end();i++){
              if(i->second>0){
                  i->second--;
                  if(DFS(i->first, cur,m,res))
                      return true;
                  i->second++;
              } 
           }
           
          for(auto i=m.begin();i!=m.end();i++){
            for (auto j=i->second.begin() ;j!= i->second.end();j++){
                if (j->second!=0){
                    res.pop_back();
                    return false;
                }
            }
          } 
          return true;
       } 
    }
};