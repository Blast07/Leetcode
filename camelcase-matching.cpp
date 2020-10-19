class Solution {
public:
    
inline bool ifUpper(char ch){
	if(ch >= 'A' && ch<='Z')
		return true;
	return false;
}
vector <bool> camelMatch(vector <string> & queries, string pattern){
	vector <bool> res;

	for (string str:queries){
		int i=0;
		int j=0;
		bool marked = false;
		while(i<str.size() && j<pattern.size()){
			if(ifUpper(str[i]) && ifUpper(pattern[j])){
				if (str[i] == pattern[j]){
					i++;
					j++;
				}else{
					res.push_back(false);
					marked = true;
					break;
				}
			}else if(ifUpper(str[i])){
				res.push_back(false);
				marked = true;
				break;
			}else if(ifUpper(pattern[j])){
				i++;
			}else{
				//both lowercase
				if(str[i]==pattern[j]){
					i++; j++;
				}else{
                    i++;
				}
			}	
		}
		if(!marked){
			while(i < str.size()){
				if(ifUpper(str[i])){
					res.push_back(false);
					marked = true;
					break;
				}
                i++; 
			}
			if (j < pattern.size()){
				res.push_back(false);
				marked = true;
			}
			if(!marked)
				res.push_back(true);
			
		}
	}
	return res;
}

};