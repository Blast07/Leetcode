class Solution {
public:
    vector <int> findRightInterval(vector <vector <int>> &intervals){
        if (intervals.size()==1)
            return {-1};

	unordered_map <int, int> mp;
        
	for (int i=0;i<intervals.size();i++){
		mp[intervals[i][0]] = i;
	}
	vector <vector <int>> temp = intervals;
	vector <int> res;


	sort(temp.begin(), temp.end());
    
       

	for (int i=0;i<intervals.size();i++){
		int l = 0;
		int r = intervals.size()-1;
		int ans = -1;
		while(l<=r){
			int m = l + (r-l)/2;
			if (temp[m][0] >= intervals[i][1]){
				ans = mp[temp[m][0]];
				r = m-1;
			}else{
				l = m+1;
			}
		}
		res.push_back(ans);
	}
	return res;
}

};