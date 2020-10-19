class Solution {
public:

int numTimesAllBlue(vector<int>& light) {
	int res = 0;
	int highest_on  = 0;
	for (int i=0;i<light.size();i++){
		highest_on = max(highest_on, light[i]);
		if (i + 1 == highest_on)
			res++;
	}
	return res;
}




};