class Solution {
public:
int longestSubarray(vector <int> &nums){
	int deleted = -1;
	int res = 0, count = 0;
	for (int i=0;i<nums.size();i++){
		if (nums[i]){
			count++;
		    res = max(res, count);
        }
		else{
			if (deleted!=-1){
				count = i - deleted - 1;	
			}

			deleted = i;
		}
	}
	if (deleted == -1){
		return count == 0 ? 0:count-1;
	}

	return res;
}


};