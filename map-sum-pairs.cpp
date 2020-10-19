struct TrieNode{
	int val;
	TrieNode * children[26];
    bool end;
	TrieNode(){
		val = 0;
        end = false;
		for (int i=0;i<26;i++)
			children[i] = NULL;
	}
};

class MapSum {
	
private:
	TrieNode *root;
	bool insertTrie(TrieNode *root, string &key,int &val, int ind){
		//returns true if key already exists
		if(ind >= key.size())	
			return false;
		else{
			TrieNode * child = root->children[key[ind] - 'a']; 
			if(!child){ //child is NULL
				child = new TrieNode();
				root->children[key[ind] - 'a'] = child;
			}else{
				//child is not null and is last char
				if (ind == key.size()-1 && child->end){
					//overwrite
					child->val = val;
					return true;
				}
			}
			child->val += val;
			if (ind == key.size()-1){
				child->end = true;
			}
			if (insertTrie(child, key, val, ind+1)){
				child->val = val;
				return true;
			}
            return false; 
		}
	}


	void sumTrie(TrieNode *root, string prefix, int ind,int &res){
		if(ind >= prefix.size())
			return;

		TrieNode *child = root->children[prefix[ind] - 'a'];
		if (!child){ //if NULL
			res = 0;
			return;
		}else{
            if(ind == prefix.size()-1){
				res = child->val;
				return;
			}
 
			sumTrie(child,prefix, ind+1,res);
		}
		
	}


public:
    /** Initialize your data structure here. */
    MapSum() {
       root = new TrieNode(); 
    }

    
    void insert(string key, int val) {
		insertTrie(root, key,val,0);
    }
    
    int sum(string prefix) {
		int res = 0;
		sumTrie(root, prefix, 0, res);
		return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */