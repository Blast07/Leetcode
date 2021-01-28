//58

int lengthOfLastWord(string s) {
  	int res = 0;
	int n = s.size()-1;

	while(n>=0 && s[n] == ' ')
		n--;

	while(n>=0 && s[n]!=' '){
		res++;
		n--;
	}

	return res;
}
