class Solution {
public:
 vector <int> maxSlidingWindow(vector <int> &nums, int k){
	deque <int> dq; //front of dq will have largest element in current window 
	vector <int> ans;
	int i=0;
	for (;i<k;i++){
		while(!dq.empty() && nums[i]>=nums[dq.back()]){
			dq.pop_back();//removing all elements smaller than current 
		}
		dq.push_back(i);
	}

	for (;i<nums.size();i++){
		//now the front is the max element in the previous window
		ans.push_back(nums[dq.front()]);
		//removing elements from front of dq which are
		//no longer part of the current window
		while(!dq.empty() && dq.front()<=i-k){
			dq.pop_front();
		}

		while(!dq.empty() && nums[i]>=nums[dq.back()]){
			dq.pop_back();//removing all elements smaller than current 
		}
		dq.push_back(i);
	}
	ans.push_back(nums[dq.front()]);
	return ans;

}


};