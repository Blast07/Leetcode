class Solution {
public:
 int trailingZeroes(int n) {
	int res =0;

	int five = 5;

	while(n){
		res += n/five;	
		n /= five;
	}
	return res;
}

};