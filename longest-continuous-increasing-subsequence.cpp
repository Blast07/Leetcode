//674

int findLengthOfLCIS(vector<int>& nums) {
	int n = nums.size();
	if (n <= 1)
		return n;
	int l = 0;
	int r = 1;
	int res = 1;
	int cur = 1;
	while(r < n){
		if (nums[r] > nums[l]){
			cur++;
			r++;
			l++;
			
			res = max(res, cur);
		}else{
			l = r;
			r = l+1;
			cur = 1;
		}
	}

	return res;
}
