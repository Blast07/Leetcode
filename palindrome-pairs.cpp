class Solution {
public:
    struct TrieNode{
	int ind;
	TrieNode *children[26];
	TrieNode(){
		ind = -1;
		for (int i=0;i<26;i++)
				children[i] = NULL;
	}
};

void insertTrie(TrieNode *node, string &word, int ind, int wordind){
	if (ind >= word.size())
			return;
	else{
		TrieNode *child = node->children[word[ind]-'a'];
		if (!child){ //if child is null
			child = new TrieNode();
			node->children[word[ind]-'a'] = child;
		}
		if(ind == word.size()-1){
			//last char
			child->ind = wordind;
			
		}
		insertTrie(child, word, ind+1,wordind);
	}
}

void checkPalindrome(TrieNode * node, string &remaingWord, int wordind, set <pair<int,int>> &res,bool empty,bool rev){

	if (node->ind!=-1){//end
		int i,j;
		for (i=0,j=remaingWord.size()-1;i<j;i++,j--){
			if(remaingWord[i]!=remaingWord[j]){
				break;
			}
		}
		if(i>=j && node->ind !=wordind){//palindrome
            if(empty){
			    res.insert({node->ind,wordind});
                res.insert({wordind,node->ind});
            }else{
                
                    if(rev){
				    res.insert({wordind, node->ind});
                    }else
				        res.insert({node->ind, wordind});
            }
		}
	
	}
	for (int i=0;i<26;i++){
		if (node->children[i]){
			char ch = 'a' + i;
			remaingWord += ch;
			checkPalindrome(node->children[i], remaingWord, wordind, res,empty,rev);
			remaingWord.pop_back();
		}
	}

}

void findPairs(TrieNode *node, string &word, int i,int &wordind,set <pair<int,int>> &res,bool rev){
        
	
	TrieNode *child = node->children[word[i] - 'a'];
	if(child){ //child not null
			if (child->ind != -1&& i==word.size()-1){//complete match
                if(child->ind != wordind){
                    if(rev){
				    res.insert({wordind, child->ind});
                    }else
				        res.insert({child->ind, wordind});
                }
                return;
			}else if(child->ind!=-1){
				//check if rest of the word is palindrome
                int j,k;
				for (j=i+1,k=word.size()-1;j<k;j++,k--){
					if(word[j]!=word[k])
						break;
				}
                if(j>=k && child->ind != wordind){
                    if(rev){
				    res.insert({wordind, child->ind});
                    }else
				        res.insert({child->ind, wordind});
                }
				
			}else if(i==word.size()-1){
				//word is finished, now traverse the trie to check for palindrome
				string remaingWord;
				for (int j=0;j<26;j++){
					remaingWord = "";
					if (child->children[j]){
						char ch = 'a' + j;
						remaingWord += ch; 
						checkPalindrome(child->children[j],remaingWord,wordind,res,false,rev); //pending 	
					}
				}
			}
            
            if(i < word.size()-1){
				findPairs(child, word, i+1, wordind, res,rev);
			}
	}
	
}

vector <vector <int>> palindromePairs(vector <string> &words){
	TrieNode *root = new TrieNode();	
    TrieNode *rev_root = new TrieNode();
	for (int i=0;i<words.size();i++){
		insertTrie(root, words[i], 0, i);
        
        string rev = words[i];
        reverse(rev.begin(), rev.end());
        
        insertTrie(rev_root, rev, 0, i);
	}
	set <pair <int,int>> res;
	for (int i=0;i<words.size();i++){
		string rev = words[i];
		reverse(rev.begin(), rev.end());
        
        if(rev.size()>0){
		    findPairs(root, rev, 0, i, res,false);
            findPairs(rev_root,words[i], 0, i, res, true);
        }
        else{
			string remaingWord;
            bool rev = false; 
			for (int j=0;j<26;j++){
				remaingWord = "";
				if (root->children[j]){
                    
					char ch = 'a' + j;
					remaingWord += ch; 
                    
					checkPalindrome(root->children[j],remaingWord,i,res, true, rev); //pending 	
				}
			}
            
        }
	}
    vector <vector <int>> ans;
    for (auto it = res.begin();it!=res.end();it++){
        ans.push_back(vector <int>{it->first,it->second});
        
    }

	return ans;
}



};