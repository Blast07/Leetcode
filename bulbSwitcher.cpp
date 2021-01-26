//319

//bulbs that are toggled odd number of times will be on
//bulbs that are toggled even number of times will be off
//numbers which are perfect squares have odd number of factors

//bool perfectSquare(int num){
//	int n = pow(num, 0.5);
//	return num == n*n;
//}
//
//int bulbSwitch(int n) {
//	
//	int res = 0;
//	for (int i=1;i<=n;i++){
//		if (perfectSquare(i))
//			res++;
//	}
//	return res;
//}

//more improved
//int bulbSwitch(int n){
//	
//	int res = 0;
//	for (int i=0;i<=n;i++){
//		if (i*i <= n)
//			res++;
//		else
//			break;
//	}
//	return res;
//}

//one liner
int bulbSwitch(int num){
	return pow(num, 0.5);
}
