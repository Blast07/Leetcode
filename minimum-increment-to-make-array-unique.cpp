class Solution {
public:
int minIncrementForUnique(std::vector <int> &A){
	if (!A.size())
		return 0;

	sort(A.begin(), A.end());
	std::unordered_set <int> mp;

	int min = A[0]+1; //min element not in map
	mp.insert(A[0]);

	int res = 0;

	for (int i=1;i<A.size();i++){
		int x;
		if (mp.find(A[i])!=mp.end()){
			res += min - A[i];
			x = min;
			min++;
		}else{
			min = A[i]+1;
			x = A[i];
		}
		mp.insert(x);
	}
	return res;
}


};