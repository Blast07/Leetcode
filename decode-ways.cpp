//91 

int f(string &s, int i, vector <int> &mem){
	if (i == s.size())
		return 1;
    else if (mem[i] != -1)
        return mem[i];
	else{

        if (s[i] == '0')
            return 0;
        int single_ch = f(s,i+1, mem);

        int double_ch = 0;
        if (i+1 < s.size()){
            int val = 10*(s[i] - '0') + (s[i+1] - '0');
            if (val <= 26){
                double_ch = f(s,i+2, mem);
            }
        }
        mem[i] = (single_ch + double_ch);
        return mem[i];
        
        
	}
	
}

int numDecodings(string s) {
    vector <int> mem(s.size(), -1);
    return f(s, 0, mem);
}
