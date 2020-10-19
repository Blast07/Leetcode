class Solution {
public:
    int countNegatives(vector <vector <int>> &grid){
	int res  =0;

	for (auto v: grid){
		int first_negative = v.size();

		int l = 0, r = v.size()-1;
		while(l<=r){
			int m = l + (r-l)/2;
			if (v[m] >= 0){
				l = m+1;
			}else{
				first_negative = m;
				r = m-1;
			}
		}

		res += v.size() - first_negative;
	}
	return res;
}

};