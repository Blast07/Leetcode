class Solution {
public:
struct TrieNode{
	bool end;
	TrieNode *child[26];
	TrieNode(){
		end = false;
		for (int i=0;i<26;i++)
			child[i] = NULL;
	}
};
void insert(string &word, TrieNode *root, int i){
    if(i>=word.size()) 
        return;
	TrieNode *newNode = root->child[word[i] - 'a'];
	if(!newNode){
		newNode = new TrieNode();
		root->child[word[i] - 'a'] = newNode;
	}
	if (i==word.size()-1){//last char
		newNode->end = true;
	}
	insert(word, newNode, i+1);
}

void findRoot(string &word, TrieNode *root, string &res, int i){
	if (i>=word.size()){
		res ="";
	}else{
		TrieNode *newNode = root->child[word[i] - 'a'];
		if (!newNode){//if null
			res = "";
			return;
		}else{
			res += word[i];
			if (newNode->end){
				return;
			}
			findRoot(word, newNode, res, i+1);
		}
	}
}

string replaceWords(vector <string> &dict, string sentence){
	TrieNode *root = new TrieNode();
	
	for (string word:dict)
		insert(word,root,0);
	
	string word = "";
	string res="";
	string ans="";
	for (int i=0;i<sentence.size();i++){
		if(sentence[i]!=' '){
			word+= sentence[i];
		}else{
			//space char
			ans = "";
			findRoot(word, root, ans, 0);
			if(ans==""){
				res += word + " ";
			}else{
				res += ans + " ";
			}
            word = "";
		}	
	}
	//last word in sentence
	ans = "";
	findRoot(word, root, ans, 0);
	if(ans==""){
		res += word;
	}else{
		res += ans;
	}
	return res;
}

};