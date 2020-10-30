//712

int f(string &s1, string &s2, int i, int j, unordered_map <string, int> &mem){
	string key = to_string(i) +"-" + to_string(j);
    if (mem.find(key) != mem.end())
		return mem[key];
	if (i==s1.size() && j == s2.size())
		return 0;
	else if (i==s1.size() || j==s2.size()){
		int cost = 0;
		while(i < s1.size()){
			cost += s1[i++];
		}

		while(j < s2.size()){
			cost += s2[j++];
		}
		mem[key] = cost;
		return  cost;

	}else{
        
		if (s1[i] == s2[j])
			 mem[key] =  f(s1, s2, i+1, j+1, mem);
		else
			mem[key] = min(s1[i] + f(s1, s2, i+1, j, mem),s2[j] + f(s1, s2, i, j+1, mem));

		return mem[key];
	}
}

int minimumDeleteSum(string s1, string s2) {
	unordered_map < string, int> mem;
	return f(s1,s2,0,0, mem);
    
}
