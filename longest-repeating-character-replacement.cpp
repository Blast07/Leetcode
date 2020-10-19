class Solution {
public:
int characterReplacement(string s, int k){
	vector <int> a(26,0);

	int i=0;
	int j=0;
	int mx =0;
	int res = 0;
	while(j<s.size()){
		int ind = s[j] - 'A';
		a[ind]++;
		
		if(mx < a[ind])
			mx = a[ind];
		if ((j-i+1) - mx<=k){
			res = max(res,j-i+1);
		}else{
			a[s[i++]-'A']--;
		}
		j++;
	}

	return res;
	
}

};