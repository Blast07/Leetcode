//1556

string thousandSeparator(int n) {
    if (n==0)
        return "0";
	string res = "";
	int count = 1;
	while(n){
		int rem = n%10; n = n/10;
      
        string ch = "";
        ch += ('0' + rem);
		if (count < 4){
			res =  ch + res;
			count++;
		}else{
			res = ch + "." + res; 
			count = 2;
		}
	}

	return res;

}
