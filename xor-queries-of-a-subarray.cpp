class Solution {
public:
vector <int> xorQueries(vector <int> &arr, vector <vector <int>> &queries){
	vector <int> res;
	vector <int> prefixXors;

	int xorr = 0; 
	for (int i=0;i<arr.size();i++){
		prefixXors.push_back(xorr);
		xorr ^= arr[i];
	}

	for (auto query:queries){
		int ans = (prefixXors[query[1]]^arr[query[1]]^prefixXors[query[0]]);
		res.push_back(ans);
	}

	return res;

}


};