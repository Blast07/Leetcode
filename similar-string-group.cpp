//839

string find(string a, unordered_map <string, pair<string, int>> &mp){
	string temp = a;
	if (mp[a].first == a)
		return a;
	else{
		mp[a] = {find(mp[a].first, mp), 1};
		return mp[a].first;	
	}
}

void union_(string a, string b, unordered_map <string, pair<string, int>> &mp){
	//making b parent of a
	//mp[find(a, mp)] = mp[find(b, mp)];
	string s1 = find(a, mp);
	string s2 = find(b, mp);

	if (mp[s1].second == mp[s2].second){
		//making s2 as root
		mp[s1] = mp[s2];
		mp[s2].second++;
	}else if (mp[s1].second > mp[s2].second){
		//s1 as root
		mp[s2].first = s1;
	}else{
		//s2 as root
		mp[s1].first = s2;
	}
}

bool similar(string &s1, string &s2){
	int diff = 0;
	for (int i=0;i<s1.size();i++){
		if (s1[i] != s2[i])
			diff++;
		if(diff>2)
			return false;
	}
	return true;
}

int numSimilarGroups(vector<string>& strs) {
	
	unordered_map <string, pair <string, int>> mp; //mp[str] = {parent, rank};

	for (auto str: strs){
		mp[str] = {str, 0};
	}

	for (auto it = mp.begin();it!=mp.end();it++){
		string str1 = it->first;
		auto jt = it;
		jt++;
		for (;jt!=mp.end();jt++ ){
			string str2 = jt->first;
			if (similar(str1, str2)){
				union_(str1, str2, mp);
			}
		}
	}

	int res = 0;
	for (auto p:mp){
		if (p.first == p.second.first)
            res++;
	}
	
	return res;

}
