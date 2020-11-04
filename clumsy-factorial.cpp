//1006

int clumsy(int n) {
	int fact = n--;
	int op = 0; //0 = *, 1 = /, 2 = +, 3 = -
	int temp =0;

	while(n){
		if (op == 0){
			fact = fact*n;
			op++;
		}
		else if(op == 1){
			fact = fact/n;
			op++;
		}else if(op == 2){
			fact = fact+n;
			op++;
		}else if(op == 3){
			op = 0;
			temp = n--;
			while(n && op <2 ){
				if (op == 0){
					temp = temp*n;
					op++;
				}
				else if(op == 1){
					temp = temp/n;
					op++;
				}
				n--;
			}
			n++;
			fact -= temp;
		}
		n--;
	}
	return fact;
}
