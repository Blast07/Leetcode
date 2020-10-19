class Solution {
public:
    
bool kLengthApart(vector <int> &nums, int k){
	
	int prev, i;
	for (i=0;i<nums.size();i++){
		if(nums[i]) 
			break;
	}
	prev = i++;
   cout<<prev<<endl; 
	for (;i<nums.size();i++){
		if (nums[i]){
			if (i - prev > k){
				prev = i;
			}else
				return false;
		}
	}
	return true;


}

};