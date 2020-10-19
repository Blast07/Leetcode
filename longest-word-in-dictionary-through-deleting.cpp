class Solution {
public:
string findLongestWord(string chars, vector <string> &dict){
	vector <string> res;
	int max  =0;
	for (string word:dict){
		int i=0;
		bool flag = false;
		for (char ch:word){
			flag = false;
			while(i<chars.size()){
				if(chars[i++] == ch){
					flag = true;
					break;
				}
			}
			if(!flag)
				break;
			
		}
		if (flag){
			if (word.size()>max){
				res.clear();
				res.push_back(word);
				max = word.size();
			}else if(word.size()==max){
				res.push_back(word);
			}
		}
	}
	sort(res.begin(),res.end());
    
	return res.size()>0 ? res[0]:"";

}

};