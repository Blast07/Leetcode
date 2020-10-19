class Solution {
public:
void merge(vector <int> &nums, int l, int m, int r, int &res){
	int i = l;
	int j = m+1;

	
	for (;i<=m;i++){
		for (;j<=r;j++){
            long long prod = nums[j]; 
            prod *=2;
			if (nums[i] > prod){
				res += m+1 - i;	
			}else
				break;
		}
	}
	//sort

	i = l, j = m+1;
	int k = 0;
	vector <int> temp(r-l+1);

	while(i <= m && j <= r){
		if (nums[i] < nums[j]){
			temp[k++] = nums[i++];
		}else{
			temp[k++] = nums[j++];
		}
	}

	while(i<=m){
		temp[k++] = nums[i++];
	}
	while(j<=r){
		temp[k++] = nums[j++];
	}

	for (k=0,i=l;k<temp.size();k++,i++){
		nums[i] = temp[k];
	}
		

}

void divide(vector <int> &nums, int l, int r, int &res){
	if (l >= r)
		return ;
	int m = l + (r-l)/2;
	divide(nums, l, m, res);
	divide(nums, m+1, r, res);

	merge(nums, l, m, r, res);


}

int reversePairs(vector<int>& nums) {
	int res  = 0;
	divide(nums, 0, nums.size()-1, res);
	return res;
}

};