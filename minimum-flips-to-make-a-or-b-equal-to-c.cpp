class Solution {
public:

int minFlips(int a,int b,int c){
	int flips = 0;	
	for (int i=0;i<31;i++){
		if (c>>i&1){ //ith bit of c is set
			if (!((a>>i&1) || (b>>i&1))){
				flips++;
			}
		}else{
			if (a>>i&1)
				flips++;
			if (b>>i&1)
				flips++;
			
		}
		
	}
	return flips;
	
}

};