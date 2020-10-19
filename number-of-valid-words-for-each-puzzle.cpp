class Solution {
public:

vector <int> findNumOfValidWords(vector <string> &words, vector <string> &puzzles){

	unordered_map <int,int> wordCount;
	vector <int> res(puzzles.size(),0);
	for (string word:words){
		int mask = 0;
		for (char ch:word){
			mask |= 1<<(ch-'a');
		}
		wordCount[mask]++;
	}
	int pn=0;
	for (string puzzle:puzzles){
		for (int i=0;i<(1<<7);i++){//each puzzle is of fixed length i.e 7
			//generating mask for each subset
			int mask =0;
            
			for (int j=0;j<7;j++){
				if (i&(1<<j))
					mask |= (1<<(puzzle[j]-'a'));
			}

			if ((mask>>(puzzle[0]-'a'))&1 && wordCount.find(mask)!=wordCount.end())
				res[pn] += wordCount[mask];

		
		}

		pn++;
	
	}
	return res;

	
}


};