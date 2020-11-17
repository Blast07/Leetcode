//303

class NumArray {
	vector <int> pre_sum;
    vector <int> nums;
    
public:
    NumArray(vector<int>& nums) {
		int n = nums.size();
        if (!n)
            return;
		pre_sum.resize(n, 0);
        this->nums = nums;

		pre_sum[0] = nums[0];
       	for (int i=1;i<n;i++){
			pre_sum[i] = pre_sum[i-1] + nums[i];	
		}
    }
    
    int sumRange(int i, int j) {
    	return pre_sum[j] - pre_sum[i] + nums[i]; 
    }
};
