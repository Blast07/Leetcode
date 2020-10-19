class Solution {
public:
bool regexMatching(string &s, string &p, int i, int j,map<pair<int,int>,bool> &mem){
	if (i>=s.size() && j>=p.size())
		return true;
	else if(j>=p.size())
		return false;
	else if(mem.find(make_pair(i,j))!=mem.end())
		return mem[make_pair(i,j)];
	else if(i>=s.size()){
		if(p[j]=='*')
			mem[make_pair(i,j)] = regexMatching(s, p, i,j+1,mem);
		else if(j+1<p.size() && p[j+1]=='*')
			mem[make_pair(i,j)] = regexMatching(s, p, i,j+2,mem);
		else
			mem[make_pair(i,j)] = false;
		return mem[make_pair(i,j)];
	}
	else{
		if ((s[i]==p[j] || p[j]=='.') && p[j+1]!='*')
			mem[make_pair(i,j)] = regexMatching(s,p,i+1,j+1,mem);
		else if ((s[i]==p[j] || p[j]=='.') && p[j+1]=='*')
			mem[make_pair(i,j)] = regexMatching(s,p,i+1,j+1,mem) || regexMatching(s,p,i,j+2,mem);
		else if(p[j]=='*'){
			if(s[i]==p[j-1] || p[j-1]=='.')
				mem[make_pair(i,j)] = regexMatching(s,p,i+1,j,mem) || regexMatching(s,p,i,j+1,mem);
			else
				mem[make_pair(i,j)] = regexMatching(s,p,i,j+1,mem);
		}else if(j+1<p.size() && p[j+1]=='*')
			mem[make_pair(i,j)] = regexMatching(s,p,i,j+2,mem);
		else
			mem[make_pair(i,j)] = false;

		return mem[make_pair(i,j)];
	}
}

    bool isMatch(string s, string p) {

        map <pair<int,int>, bool> mem;
        return regexMatching(s,p,0,0,mem);
    }
};