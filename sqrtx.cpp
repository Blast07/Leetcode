//69

int mySqrt(int x) {
	int l = 1, r = x;
	int res = 0;
	while(l <= r){
		int m = l + (r-l)/2;
        long long sqr = (long long)m*m;
		if (sqr > x)
			r = m-1;
		else {
			res = m;
			l = m+1;
		}
	}
	return res;

}
