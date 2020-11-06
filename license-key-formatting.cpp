//482

string licenseKeyFormatting(string s, int k) {
	string res = "";
	int cur_size = 0;

	for (int i=s.size()-1;i>=0;i--){
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')){
			res += s[i];	
			cur_size++;
		}
		else if(s[i] >= 'a' && s[i]<= 'z' ){
			res += ('A' + (s[i] - 'a'));
			cur_size++;
		}
		if (cur_size == k){			
            res += '-';
			cur_size = 0;
		}
	}
	if (res.back() == '-'){
        res.pop_back();
    }
    reverse(res.begin(), res.end());
	return res;
}
