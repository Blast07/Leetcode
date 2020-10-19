class Solution {
public:
 int firstMissingPositive( vector <int> nums){
	int mx =0;
	for (int i=0;i<nums.size();i++){//removind -ve numbers
		if(nums[i]<=0)
			nums[i] = nums.size()+2;
		else
			mx = max(mx, nums[i]);
	}

	for (int i=0;i<nums.size();i++){
		if (abs(nums[i])<nums.size() && nums[ abs(nums[i]) ] >0){
				nums[ abs(nums[i]) ] *=-1;
        }
	}
	int i=1;
	while(i<nums.size() && nums[i]<0)
		i++;
	if (mx==i)
		i++;
	return i;
}


};