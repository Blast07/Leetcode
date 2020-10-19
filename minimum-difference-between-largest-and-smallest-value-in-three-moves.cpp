class Solution {
public:
int minDifference(vector <int> &nums){

	int n =  nums.size();
	if (n<=3)
		return 0;

	sort(nums.begin(), nums.end());
    int res	= min(nums[n-1-3] - nums[0], nums[n-1] - nums[3]);
    
    for (int i=1;i<3;i++)
        res  = min(res, nums[n-2]-nums[i]);
    
    for (int i=n-2;i>=n-3;i--)
        res = min(res, nums[i]-nums[1]);
    return res;
    
	
}

};