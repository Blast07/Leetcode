//357

int countNumbersWithUniqueDigits(int n) {
	if (n == 0)
		return 1;
	else if(n == 1)
		return 10;
	
	int res = 10;
	int mul = 9;
	for (int i=2, t=9;i<=n;i++,t--){
		mul *= t;	
		res += mul;
	}
	return res;
}
