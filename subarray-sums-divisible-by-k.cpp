class Solution {
public:
    int subarraysDivByK(vector <int> &A, int K){
	int res = 0, cum =0;
	unordered_map <int,int> mp;
	mp[0] = 1;

	for (int i=0;i<A.size();i++){
		cum += A[i];
		int rem = cum%K;
        if(rem < 0){
            rem +=K;
        } 
		if(mp.find(rem)!=mp.end())
			res += mp[rem];
		
		mp[rem]++;
	}
	return res;
}

};