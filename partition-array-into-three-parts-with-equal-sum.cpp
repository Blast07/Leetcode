//1013

bool canThreePartsEqualSum(vector<int>& a) {
	int total = 0;
	for(int x:a)
		total += x;

	if (total%3)
		return false;
		
	int sum = 0;
	bool first = false;
	int i = 0;
	for (;i<a.size();i++){
		sum += a[i];
		if (sum == total/3){
			if (!first)
				first = true;
			else{
				i++;
				break;
			}
			sum = 0;
		}
	}
	return i!=a.size();

}
