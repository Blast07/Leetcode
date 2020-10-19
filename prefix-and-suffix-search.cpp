//745 prefix and suffix search

struct TrieNode{
	set <int> weights;
	TrieNode *children[26];

	TrieNode(){
		for (int i=0;i<26;i++)
			children[i] = NULL;
	}
	
};

void insertTrie(TrieNode *node, string &word, int i,int wt){
	if (i >= word.size()){
		return;
	}else{
		
		TrieNode * child = node->children[word[i]-'a'];
		if (!child){//child is null
			child = new TrieNode();
			node->children[word[i] - 'a'] = child;
		}
		child->weights.insert(wt);
		insertTrie(child, word, i+1, wt);
	}
}

TrieNode *getLastNode(TrieNode *node ,string &word,  int i){
	TrieNode *child = node->children[word[i] - 'a'];
	if (i==word.size()-1)
		return child;

	if(!child)//child is null
		return NULL;
	else return getLastNode(child, word, i+1);
}






class WordFilter {
	TrieNode *pre_root;
	TrieNode *suf_root;
    int size;
    unordered_map <string,int> m;
public:
    WordFilter(vector<string>& words) {
        for (int i=0;i<words.size();i++){
            m[words[i]] = i;
        }
        size = words.size()-1;
		pre_root = new TrieNode();
		suf_root = new TrieNode();/*
		for (int i=0;i<words.size();i++){
			insertTrie(pre_root, words[i], 0, i); //prefix trie
            
			string temp = words[i]; reverse(temp.begin(), temp.end());
			insertTrie(suf_root, temp, 0, i); //suffix trie
		}*/
        for (auto it=m.begin();it!=m.end();it++){
            string word = it->first;
            insertTrie(pre_root, word, 0, it->second);
            
            string temp = it->first; reverse(temp.begin(),temp.end());
            insertTrie(suf_root, temp, 0 , it->second);
        }
        
    }
    
    int f(string prefix, string suffix) {
        
        if (prefix=="" && suffix=="")
            return size;
        
        TrieNode * pre_node = NULL;
        TrieNode * suf_node = NULL;
        if (prefix!="")
       	    pre_node = getLastNode(pre_root, prefix, 0); 
		int res=-1;
		if(!pre_node && prefix!=""){ //prefix not found
			return -1;
        }
        
        string suf = suffix;
        reverse(suf.begin(), suf.end());
        if(suffix!="")
		    suf_node = getLastNode(suf_root, suf, 0);
		if (!suf_node && suffix!=""){ //suffix not found
			return -1;
        }
        if (prefix == ""){
            return *(suf_node->weights.rbegin());
        }
        if (suffix == ""){
            
            return *(pre_node->weights.rbegin());
        }

		auto pit=pre_node->weights.begin();

		for (; pit!=pre_node->weights.end(); pit++){
			auto sit = suf_node->weights.begin();
			for (; sit!=suf_node->weights.end(); sit++)	{
				if (*pit == *sit)
					res = *pit;
			}
		}
		return res;
    }
};


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */