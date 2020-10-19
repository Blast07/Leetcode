class Solution {
public:
vector <int> corpFlightBookings(vector <vector <int>> &bookings, int n){
	vector <int> ans(n+1, 0);
	for (vector <int> bkg:bookings){
		ans[bkg[0]-1] += bkg[2];
		ans[bkg[1]] -= bkg[2];
	}
	for (int i=1;i<ans.size();i++){
		ans[i]+=ans[i-1];
	}
	ans.pop_back();
	return ans;
}


};