
class Solution {
public:
int minSubarray(vector <int> &nums, int p){
	
	unordered_map <int,int> mp;
	mp[0] = -1;

	int cur = 0;
    int mod = 0;
	for (int x:nums)
		mod = (mod + x)%p;
        
	if (mod == 0)
		return 0;
	
    int res = INT_MAX;
	for (int i=0;i<nums.size();i++){
        
		cur = (cur + nums[i])%p;
        int diff = (cur - mod + p)%p;
        
		if (mp.find(diff) != mp.end()){ //subarray with sum = 'mod' found
		    res = min(res, i - mp[diff]);
		}
        
        mp[cur] = i;
	}
	return (res == nums.size() || res == INT_MAX? -1:res);
}
};