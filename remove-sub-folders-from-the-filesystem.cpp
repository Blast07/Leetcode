class Solution {
public:
vector <string> removeSubfolders(vector <string> &folders){

	sort(folders.begin(), folders.end());
	vector <string> res;

	unordered_set <string> folder_set;
	for (string str:folders){
		string temp = "/";
		bool sub  = false;
		for (int i=1;i<str.size();i++){
			if (str[i]=='/'){
				if (folder_set.find(temp)!=folder_set.end()){
					sub = true;	
					break;
				}

			}
			temp += str[i];
		}
		if (!sub){
            folder_set.insert(temp); 
			res.push_back(temp);
		}
	}
	return res;
}

};