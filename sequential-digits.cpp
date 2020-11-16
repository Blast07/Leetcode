//1291

int digits(int num){
	int d = 0;
	while(num){
		d++;
		num = num/d;
	}

	return d;

}

int getSeqNum(int i, int min_d){
	int num = 0;
	while(min_d){
		num = num*10 + i;
		i++;
		min_d--;
	}
	return num;
}
vector<int> sequentialDigits(int low, int high) {	 
	int min_d = digits(low);
	int max_d = digits(high);
	vector <int> res;
	while(min_d <= max_d){
		
		for (int i=1;i<9-min_d+1;i++){
			int num = getSeqNum(i, min_d);
			if (num < low){
				continue;
			}else if(num > high){
				break;
			}

			res.push_back(num);
		}

		min_d++;	
	}

	return res;
}
