class Solution {
public:
    map <pair<int,int>,int> mem; 
    int minTotal(vector <vector <int>> &triangle, int lvl, int i){
        if (lvl == triangle.size()-1)
            return triangle[lvl][i];
        else if(mem.find(make_pair(lvl,i))!=mem.end()){
            return mem[{lvl,i}];
        }
        else{
            mem[{lvl,i}] = triangle[lvl][i] + min(minTotal(triangle,lvl+1,i),
                                          minTotal(triangle,lvl+1,i+1));
            return mem[{lvl,i}];
        }
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        mem.clear();
        return minTotal(triangle, 0,0);
    }
};