//5

bool helper(string &s, int l, int r, string &res, vector <vector <int>> &mem){
	if( l == r+1)
		return true;
	else if (l == r){
		if (1 > res.size()){
			res = s[l];
		}
		return true;
	}else if(mem[l][r]!=-1){
		return mem[l][r];
	}
	else{

		if (s[l] == s[r] && helper(s, l+1, r-1, res, mem)){
       
			if (r-l+1 > res.size()){
				res = s.substr(l, r-l+1);
			}
			mem[l][r] = 1;
			return true;
		}

		helper(s, l, r-1, res, mem);
		helper(s, l+1, r, res, mem);
		
		mem[l][r] = 0;
		return false;
	}

}

string longestPalindrome(string s) {
	string res = "";
	vector <vector <int>> mem(s.size(), vector <int> (s.size(), -1));
	helper(s, 0, s.size()-1, res, mem);
	
	return res;
}
