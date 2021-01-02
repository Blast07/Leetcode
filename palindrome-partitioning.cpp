//131

bool isPalin(string &s){
	for (int i=0, j=s.size()-1; i<j;i++,j--){
		if(s[i] != s[j])
			return false;
	}
	return true;
}

void getPartitions(string s,vector <string> &cur,vector <vector <string>> &res){
	if (s.size() == 0){
		res.push_back(cur);
	}else{
		
		for (int i=0;i<s.size();i++){
			string sub = s.substr(0, i+1);
			if (isPalin(sub)){
				cur.push_back(sub);
				string rem = s.substr(i+1);
				getPartitions(rem, cur, res);
				cur.pop_back();
			}
		}
	}
}

vector<vector<string>> partition(string s) {
	
	vector <vector <string>> res;
	vector <string> cur;

	getPartitions(s, cur, res);
	
	return res;
}
