#define llint long long int
class Solution {
public:

    
llint f(llint mid, llint a, llint b, llint c){
	//returs number of ugly numbers <= to mid
	return mid/a + mid/b + mid/c -mid/lcm(a, b) - mid/lcm(a, c) - mid/lcm(b,c) + mid/lcm(a, lcm(b, c));

}

int nthUglyNumber(int n, int a, int b, int c){
	llint l = min({a,b,c}), r = 2000000000, ans;

	while(l<=r){
		llint mid = l + (r-l)/2;
		if ( f(mid, a, b, c) < n )
			l = mid+1;
		else{
			ans = mid;
			r = mid-1;
		}
	}
	return ans;
}


};