class Solution {
public:
int numberOfSteps(int num){
	//check odd-even using bit manipulation
	//odd-numbers always have first bit set to 1
	//even have first bit set to 0
	int steps = 0;
	while(num){
		if((num&1)){//odd
			//num/=2;
			num--;
		}else //even
			num = num>>1;
		steps++;
	}
	return steps;
}

};