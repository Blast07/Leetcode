//1177

bool check(string &s, vector <int> &q, vector <vector <int>> &pre){
	vector <int> char_count = pre[q[1]+1];
	int extras = 0;
	for (int i=0;i<26;i++){
		char_count[i] -= pre[q[0]][i];
		extras += char_count[i]%2;
	}

	extras /= 2;

	return extras <= q[2];
}

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
	int n = s.size();
	//prefix char count
	vector <vector <int> > pre(n+1, vector <int>(26, 0));
    
    vector <bool> res;
	for (int i=0;i<n;i++){
		pre[i+1] = pre[i];
		pre[i+1][s[i] - 'a']++;
	}
	
	for (auto q:queries){
		res.push_back(check(s, q, pre));		
	}

	return res;
}


/*
Brute force TLE

bool check(string s, vector <int> q){
	vector <int> a(26, 0);
	int m = q[0] + (q[1]-q[0])/2;

	for (int i=q[0];i<m;i++){
		a[s[i] - 'a']++;
	}
	for (int i=m;i<=a[1];i++){
		a[s[i] - 'a']--;
	}
	for (int i=0;i<26;i++){
		if (a[i] != 0){
			if (q[2] > 0){
				q[2] -= abs(a[i]);	
			}else
				return false;

		}
	}
	return true;
}

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
	vector <bool> res;
	for (vector <int> q: query){
		res.push_back(check(s, q));

	}        
	return res;
}
*/
