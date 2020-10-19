struct TrieNode{
	int count;
	TrieNode *children[26];
	TrieNode(){
		count = 0;
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
	}
};
TrieNode *root;
class Solution {
	
	struct comparator{
		bool operator()(string str1, string str2) const{
			if (getCount(root, str1, 0) != getCount(root ,str2, 0))
				return getCount(root, str1, 0) > getCount(root, str2, 0);
			else
				return str1  < str2;
	
		}
	};
    struct sortComparator{
	bool operator()(string str1, string str2) const{
		if (getCount(root,str1,0) != getCount(root,str2,0))
			return getCount(root,str1,0)> getCount(root, str2,0);
		else
			return str1  < str2;

	}
};

	static int getCount(TrieNode *root, string &word, int i){
		TrieNode *child = root->children[word[i]-'a'];
		if (child->count>0)
			return child->count;

		return getCount(child, word, i+1);
	
	}

	void insert(TrieNode *root, string &word, int i){
		if(i >= word.size())
			return;
		else{
			TrieNode *child = root->children[word[i]-'a'];
			if (!child){//null
				child  = new TrieNode();
				root->children[word[i] - 'a'] = child;
			}

			if (i == word.size()-1)
				child->count++;
			insert(child, word, i+1);
		}
	}
	
	void findtopk(TrieNode *root, string &word, vector <string> &res,int k){

		for (int i=0;i<26;i++){
			if (root->children[i]!=NULL){
				char ch = 'a' + i;
				word += ch; 
				if (root->children[i]->count>0){
					if(res.size()<k){
						res.push_back(word);
                        
						if(res.size()==k){
							make_heap(res.begin(), res.end(), comparator());
						}
					}else{
						string frnt = res.front();
                        
                        
                            
						if (getCount(::root,frnt,0) < getCount(::root, word, 0)){
							pop_heap(res.begin(), res.end(), comparator());
							res.pop_back();
							
							res.push_back(word);
							push_heap(res.begin(), res.end(), comparator());	
						}
					}
				}
				
				findtopk(root->children[i], word, res, k);
				
				word.pop_back();
			}
		}
	
	}
public:

	Solution(){
		root = new TrieNode();
	}

    vector<string> topKFrequent(vector<string>& words, int k) {
		for (string word:words)
			insert(root ,word, 0);
        
	
		vector <string> res;
        string word=""; 
		findtopk(root, word, res, k);
        sort(res.begin(), res.end(), sortComparator());
		return res;
        
    }
};

