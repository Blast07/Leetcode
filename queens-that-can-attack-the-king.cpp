class Solution {
public:
   vector <vector<int>> queensAttacktheKing(vector <vector<int>>&queens, vector<int> &king){
    vector <vector<int>> res;
    vector <vector<int>> dirs{{0,-1},{0,1},
    {-1,0},{1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
    
    set <pair<int,int>> m;
    for (auto q:queens)
        m.insert(make_pair(q[0],q[1]));
    
    
    for (auto dir:dirs){
        int x=king[0]+dir[0];
        int y=king[1]+dir[1];
        while(x>=0 && x<8 && y>=0 && y<8 
        ){
            //if queen on x,y
            if (m.find(make_pair(x,y))!=m.end()){
                res.push_back(vector <int>{x,y});break;
            }
            x = x+dir[0];
            y = y+dir[1];
            
        }
    }
    return res;
}
};