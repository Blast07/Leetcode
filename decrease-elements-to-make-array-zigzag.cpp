class Solution {
public:
int movesToMakeZigzag(vector<int>& nums) {
	
	vector <int> copy = nums;    

	int even_moves = 0;
	int odd_moves = 0;

	for (int i=0;i<copy.size();i+=2){
		if (i-1>=0){
			if (!(copy[i] > copy[i-1])){
				int diff = copy[i-1] - copy[i] + 1;
				even_moves += diff;
				copy[i-1] -= diff;
			}
		}

		if (i+1<copy.size()){
			if (!(copy[i] > copy[i+1])){
				
				int diff = copy[i+1] - copy[i] + 1;
				even_moves += diff;
				copy[i+1] -= diff;
			}
		}
	}

	copy = nums;

	for (int i=1;i<copy.size();i+=2){
		if (i-1>=0){
			if (!(copy[i] > copy[i-1])){
				int diff = copy[i-1] - copy[i] + 1;
				odd_moves += diff;
				copy[i-1] -= diff;
			}
		}

		if (i+1<copy.size()){
			if (!(copy[i] > copy[i+1])){
				
				int diff = copy[i+1] - copy[i] + 1;
				odd_moves += diff;
				copy[i+1] -= diff;
			}
		}
	}
	return min(even_moves, odd_moves);

}

};