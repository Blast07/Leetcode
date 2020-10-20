//354

bool comparator(vector <int> v1, vector <int> v2){
	if (v1[0] > v2[0] && v1[1] > v2[1])
		return true;
	else if (v1[0] == v2[0])
		return v1[1] > v2[1];
	else if (v1[1] == v2[1])
		return v1[0] > v2[0];
	else if (v1[0] > v2[0]) 
		return true;
    else
        return false;
}

class Solution {
public:
    
int maxEnvelopes(vector <vector <int>> &envelopes){
	int n = envelopes.size();
    if (n==0)
        return 0;
	vector <int> mem(n, 1);
	sort (envelopes.begin(), envelopes.end(),comparator);
	int res = 1;
	
	for (int i = n-2;i>=0;i--){
		for (int j=i+1;j<n;j++){
			if (envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                mem[i] = max(mem[i], 1+mem[j]);
				res = max(mem[i], res);
			}
		}
	}
	return res;
}

};
