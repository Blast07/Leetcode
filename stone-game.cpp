class Solution {
public:
    bool stoneGame(vector <int> &piles,int &my_score, int &his_score,
				int start, int end, int turn,vector <vector <int>> &mem){
	if (start==end){
		if(turn)
			my_score +=piles[start];
		else
			his_score += piles[start];
	}
	else if(mem[start][end]!=-1){
		return mem[start][end];
	}	
	else{
		int my_score_l;
		int my_score_r;
		int his_score_l;
		int his_score_r;
		if (turn){
			my_score_l = my_score + piles[start];
			my_score_r = my_score + piles[end];
			his_score_l = his_score;
			his_score_r = his_score;
		}else{
		
			 my_score_l = my_score;
			 my_score_r = my_score; 
			 his_score_l = his_score + piles[start];
			 his_score_r = his_score + piles[end];
		}

			stoneGame(piles,my_score_l,his_score_l,start+1,end,!turn,mem);
			stoneGame(piles,my_score_l,his_score_r,start,end-1,!turn,mem);
			mem[start][end]  = (my_score_l>his_score_l || my_score_r>his_score_r);
			return mem[start][end];
	}
    return false; 

}
    bool stoneGame(vector<int>& piles) {
         int my =0;
         int his =0;
         vector <vector <int>> mem(piles.size(), vector<int>(piles.size(),-1));
         return stoneGame(piles,my,his,0,piles.size()-1,true,mem);
    }
};