//1340

int helper(int i, int &d, vector <int> &arr, vector <int> &mem){
	if (i>=arr.size())
		return;
	else if(mem[i])
		return mem[i];
	else{
		int res = 0;
		for (int x=1;i+x<arr.size() && x<=d;x++){
			if (arr[i] > arr[i+x])
				res = max(res, helper(i+x, d, arr, mem));
			else
				break;
		}

		for (int x=1;i-x>=0 && x<=d ;x++){
			if (arr[i] > arr[i-x])
				res = max(res, helper(i-x, d, arr, mem));
			else
				break;
		}
		mem[i] = res + 1;
		return mem[i];
	}

}

int maxJumps(vector<int>& arr, int d) {
	vector <int> mem(arr.size(), 0);
	int res = 0;
	for (int i=0;i<arr.size();i++){
		res = max(res, helper(i, d, arr, mem));
	}

	return res;
}
