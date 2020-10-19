class Solution {
public:
    int hIndex(vector<int>& c) {
        	int n=c.size(), l=0, r=n, m;
	while(l<r) m = (l+r+1)/2, m <= c[n-m] ? l = m : r = m-1;
	return l;

    }
};