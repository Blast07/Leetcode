struct TrieNode{
	bool end;
	TrieNode *child[26];

	TrieNode(){
		end = false;
		for(int i=0;i<26;i++){
			child[i] = NULL;
		}
	}

};
class Solution{
		TrieNode* root;

		void insertTrie(string &word, TrieNode *root,int cur){
			if(cur >= word.size())
				return;

			TrieNode *newNode = root->child[word[cur]-'a'];
			if(!newNode){ //null
				newNode = new TrieNode();
				root->child[word[cur]-'a'] = newNode;
			}
		
			if(cur == word.size()-1){
				newNode->end = true;
			}
			insertTrie(word, newNode, cur+1);
		}
		void getLongest(TrieNode *root, string &str,string &res){
			for (int i=0;i<26;i++){
				TrieNode  *node= root->child[i];
				if(node && node->end){
					str += (i+'a');
					if(str.size() > res.size())
						res = str;
					getLongest(node,str,res);
					str.pop_back();
				}
			}
		}
	public:
    
		Solution(){
			root = new TrieNode();
		}
		string longestWord(vector <string> &words){
			for (string word:words)
				insertTrie(word,root,0);

			string res = "";	
			string str = "";
			getLongest(root,str,res);
			return res;
	
		}
};
