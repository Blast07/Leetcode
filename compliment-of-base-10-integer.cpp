//1009

int bitwiseComplement(int n) {
	if (n == 0)
		return 1;
	int msb = log2(n);	    
	int mask = pow(2,msb+1) - 1;
	int res = mask&(~n);

	return res;
}
