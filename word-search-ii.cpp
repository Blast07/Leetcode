class Solution {
public:
struct TrieNode {
	bool end;
	bool included;
	TrieNode *children[26];
	TrieNode(){
		end = false;
		included = false;
		for (int i=0;i<26;i++){
			children[i] = NULL;
		}
	}
};

void insertTrie(TrieNode *node, string &word, int ind){
	if(ind >= word.size())
		return;
	else{
		TrieNode *child = node->children[word[ind]-'a'];
		if(!child){ //if child is null
			child = new TrieNode();
			node->children[word[ind]-'a'] = child;
		}
		if (ind == word.size()-1)//last char of word
			child->end = true;

		insertTrie(child, word,ind+1);
		
	}
}

void DFS(TrieNode *node, int i, int j,vector <vector <char>> &board, vector <vector <int>> &visited, string word, vector <string> &res){
	if (!(i>=0 && i<board.size() && j>=0 && j <board[0].size())  || visited[i][j]) //if not in the bounds
		return;

	TrieNode *child = node->children[board[i][j]-'a'];

	if (!child) // child is null
		return;
	
	word += board[i][j];	
	visited[i][j] = true;
	if (!child->included && child->end){
		res.push_back(word);
		child->included = true;
	}
	DFS(child, i+1, j, board, visited, word, res);
	DFS(child, i-1, j, board, visited, word, res);
	DFS(child, i, j-1, board, visited, word, res);
	DFS(child, i, j+1, board, visited, word, res);

	visited[i][j] = false;

	return;
}

vector <string> findWords(vector <vector <char>> &board, vector <string> &words){
	//mxn
	int m = board.size();
	int n = board[0].size();

	TrieNode *root = new TrieNode();
	
	for (string word:words)
		insertTrie(root, word, 0);

	vector <vector <int>> visited(m, vector <int>(n, false));
	vector <string> res;

	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			string word="";
			DFS(root, i, j, board, visited, word, res);
		}
	}
	return res;
	
}

};