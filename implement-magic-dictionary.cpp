
struct TrieNode{
	bool end;
	TrieNode *child[26];
	TrieNode(){
		this->end = false;
        for (int i=0;i<26;i++)
            child[i] = NULL;
	}
};

class MagicDictionary {
	
	TrieNode *root;

	void insert(string &word,TrieNode *root,int cur){
		if(cur>= word.size())
			return;
		if((root->child[word[cur] - 'a']) == NULL){
			//char does not exists
			TrieNode *newNode = new TrieNode();
			if(cur == word.size()-1 ){ //last char
				newNode->end = true;
			}
			root->child[word[cur] - 'a'] = newNode;
			insert(word, newNode, cur+1);
		}else{
			//char exists
            TrieNode *node = root->child[word[cur]-'a'];
            if(cur==word.size()-1)
                node->end = true;
			insert(word, node, cur+1);
		}
	
	}
	bool trieSearch(string &word, TrieNode *root, int cur,bool changed){
		if(cur==word.size()){
            return root->end && changed;
        }
		else{
			for (int i=0;i<26;i++){
                bool tempc = changed;
				if(root->child[i]!=NULL){
                    char ch = i+'a';
                    
                    if(i != word[cur]-'a'){
                        
                        if(tempc){
                           continue;
                        }
                        tempc = true;
                    }
					if(trieSearch(word, root->child[i], cur+1, tempc))
						return true;
				}
			}
           return false; 
		}
	}
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
		root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
    	for (string word:dict){
			insert(word,root,0); // word root and ith char
		}     
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
		bool changed = false;
		return trieSearch(word,root,0,changed);
    }
};


/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */