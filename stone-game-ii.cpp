class Solution {
public:
   
   int mem[101][10001][2];
    
   int stoneGame2(vector <int> &piles, int start, int M, int turn){
	if (start>=piles.size())
		return 0;
	else if(mem[start][M][turn]!=-1){
		return mem[start][M][turn];
	}
    else{
		if (turn){
			//alex's turn
			int k = start;
			int stones = 0;
			int sum =0;
			int max_val = 0;
			for (int x=1;x<=2*M;x++){
				while(k<start+x && k<piles.size()){
					sum += piles[k];
					k++;
				}
				stones = sum;
				stones += stoneGame2(piles, start+x,max(x,M),false);
				max_val = max(stones, max_val);
			}
   			mem[start][M][turn] = max_val;         
			return max_val;
		}else{
			//lee's turn
			int min_val = INT_MAX;
			int stones;
			for (int x=1;x<=2*M;x++){
				stones = stoneGame2(piles,start+x,max(x,M),true);
				min_val = min(stones, min_val);
			}
            mem[start][M][turn] = min_val;
			return min_val;
		}
	}
}
 
    
    int stoneGameII(vector<int>& piles) {
       for (int i=0;i<101;i++){
		for (int j=0;j<10001;j++){
			for (int k=0;k<2;k++)
				mem[i][j][k] = -1;
		}
	}	

        return stoneGame2(piles, 0, 1, true);   
    }
};