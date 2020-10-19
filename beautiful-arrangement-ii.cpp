class Solution {
public:
vector <int> constructArray(int n, int k){
	vector <int> res(n,0);	
	vector <bool> used(n+1, false);

	for (int i=0;i<n;i++)
		res[i] = i+1;

	int i = 1;
	used[1] = true;
	while(k){
		if (res[i-1] - k >0 && !used[res[i-1]-k]){
			res[i] = res[i-1] - k;
			used[res[i-1]-k] = true;
		}else if(res[i-1] + k <=n && !used[res[i-1]+k]){
			res[i] = res[i-1] + k;
			used[res[i-1]+k] = true;
		}
		k--;
        i++;
	}

	return res;
}

};