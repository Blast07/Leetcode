class Solution {
public:
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
	int M = *max_element(candies.begin(),candies.end());
	vector <bool> res;
	for (auto c:candies){
		if (c+extraCandies >= M)
			res.push_back(1);
		else
			res.push_back(0);
	}

	return res;
}


};