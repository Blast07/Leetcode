//1387

unordered_map <int,int> mp;
int power(int i){
	if (i==1)
		return 0;
	else if (mp.find(i)==mp.end()){
		
		if (i%2){
			mp[i] = 1 + power(3*i+1);
		}else
			mp[i] = 1 + power(i/2);
	}

	return mp[i];
}

bool comparePower(int a, int b){
	int pa = power(a);
	int pb = power(b);

	if (pa == pb){
		return a<b;
	}else 
		return pa < pb;
}


int getKth(int lo, int hi, int k) {
	mp.clear();	
	int n = hi-lo+1;
	vector <int> nums(n);

	for (int i=0;i<n;i++){
		nums[i] = i+lo;
	}

	sort(nums.begin(), nums.end(), comparePower);
	return nums[k-1];
}
