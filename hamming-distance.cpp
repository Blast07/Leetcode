class Solution {
public:
int hammingDistance(int x,int y){
	int diff = x^y;
	int dist = 0;
	for (int i=0;i<31;i++){
		if ((diff>>i)&1)
			dist++;
	}
	return dist;
}


};