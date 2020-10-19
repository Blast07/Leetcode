class Solution {
public:
    vector <int> parent;
    
    int find(char ch){
        int i = ch-'a';
        while(i!=parent[i]){
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
    
    void union_(char a, char b){
        int par_a = find(a);
        int par_b = find(b);
        if (par_a!=par_b)
            parent[par_b] = par_a;
    }
    
    void deunion(char a,char b){
       parent[a-'a'] = a-'a';
       parent[b-'a'] = b-'a';
    }
    
    bool equationsPossible(vector<string>& equations) {
      for (int i=0;i<26;i++)
          parent.push_back(i);
      for (auto eq:equations){
          if (eq[1]=='='){
              union_(eq[0],eq[3]);
          }else{
              if (find(eq[0])!=find(eq[3])){
                  continue; //already in different set
              }
              deunion(eq[0], eq[3]);
          }
      }
      for (auto eq:equations){
          if (eq[1]=='='){
              if(find(eq[0])!=find(eq[3]))
                  return false;
              
          }else{
              if (find(eq[0])==find(eq[3]))
                  return false;
          }
      }
      return true;
    }
};