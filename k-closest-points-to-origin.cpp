class Solution {
public:
    struct myComp{
    bool operator()(pair <vector<int>, int> p1, pair <vector <int>,int> p2){
        return p1.second > p2.second;
    }};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            vector <pair<vector <int>,int>> v;
            for (int i=0;i<points.size();i++){
                v.push_back(make_pair(points[i],(points[i][0]*points[i][0]+points[i][1]*points[i][1])));
            }
            make_heap(v.begin(),v.end(),myComp());
            for (int i=0;i<v.size();i++)
                cout<<v[i].second<<endl;
            int count=0;
            vector <vector <int>> res;
            while(count<K && v.size()){
                res.push_back(v.front().first);
                pop_heap (v.begin(),v.end(),myComp()); 
                v.pop_back();
                count++;
            }
            return res;

    }
};