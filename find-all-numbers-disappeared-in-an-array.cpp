class Solution {
public:
   vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector <int> res;

	for(int i=0;i<nums.size();i++){
		if (nums[abs(nums[i])-1] >0)
			nums[abs(nums[i])-1] *=-1; //marking as -ve
	}
	for (int i=0;i<nums.size();i++){
		if (nums[i]>0){ //didnt occur
			res.push_back(i+1);	
		}
	}
	return res;
}

};