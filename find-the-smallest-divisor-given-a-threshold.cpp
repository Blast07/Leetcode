class Solution {
public:
   int dsum(vector <int> &nums, int m){
	int sum = 0;
	for (int i=0;i<nums.size();i++){
		sum += ceil(float(nums[i])/float(m));
	}
	return sum;
}

int smallestDivisor(vector <int> &nums, int threshold){
	
	int l = 1;
	int r = *max_element(nums.begin(), nums.end());
	int ans = -1;

	while(l<=r){
		int m = l + (r-l)/2;
		if (dsum(nums, m) <= threshold){
			ans = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return ans;
}
};