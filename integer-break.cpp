//343

int	integerBreak(int n){
	int res = n-1; //for i = 1
	int temp = 0;
    
	for (int i = 2;i<n;i++){
        if (n/i < 2)
            break;
		else if (n%i == 0){
			temp = pow(i, n/i);
		}else{
			temp = max(pow(i,n/i)*(n%i) , pow(i, n/i-1)*(i+n%i));
		}
        
        if (temp > res)
            res = temp;
        else
            break;
	}
	return res;
}
