class Solution {
public:
int maxScoreOfSubset(int curBit, vector <string> &words, unordered_map <char,int> &letterCount,vector <int> &score){
	if (curBit==words.size())
		return 0;
	else{
		//max of (withoutIncluding, including 1, including 2)
		int scoreWithoutIncluding = maxScoreOfSubset(curBit+1,words,letterCount,score);
		int scoreIncludingOnce = 0;
		

		bool canForm = true;
		int curScore  =0;
		for (int i=0;i<words[curBit].size();i++){
			int ch = words[curBit][i];
			if (letterCount[ch]){
				letterCount[ch]--;
				curScore += score[ch-'a'];
			}else{
				canForm = false;
				curScore = 0;
				for (int j=0;j<i;j++){ //resetting count

					int newCh = words[curBit][j];
					letterCount[newCh]++;
				}
				break;
			}
		
		}
		if (canForm){
			scoreIncludingOnce = curScore+maxScoreOfSubset(curBit+1, words,letterCount,score);
			//resetting count
			for (int i=0;i<words[curBit].size();i++){
				int ch = words[curBit][i];
				letterCount[ch] ++; 
			}

		}
		return max({scoreWithoutIncluding, scoreIncludingOnce});
	
	}

}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
	unordered_map <char,int> letterCount;
    for (char ch:letters)
       letterCount[ch]++;

	return maxScoreOfSubset(0,words,letterCount,score);

        
}

};