class Solution {
public:
    vector <vector<string>> groupAnagrams(vector<string>& strs){
    vector<vector<string>> res;
    unordered_map <string,vector <string>> m;
    for (auto s:strs){
        vector <int>temp (26,0);
        for (auto ch:s){
            temp[ch-'a']++;
        }
        string key="";
        for (auto t:temp){
            key += 'a'+t;
        }
        if (m.find(key)!=m.end()){
            m[key].push_back(s);
        }else{
            m[key] = vector<string>{s};
            
        }
    }
    for (auto s=m.begin();s!=m.end();s++){
        if(s->second.size())
            res.push_back (s->second);
    }
    return res;
}
        
    
};