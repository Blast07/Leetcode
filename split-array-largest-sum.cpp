class Solution {
public:
    bool isValid(vector<int> &nums, int m, int guessed_sum){
	int count = 1;
	int cumulative_sum = 0;
	for (int i=0;i<nums.size();i++){
		if (cumulative_sum + nums[i] > guessed_sum){
			count++;
			cumulative_sum = 0;
		}
        cumulative_sum += nums[i];
	}

	return count <= m;
}

int splitArray(vector <int> &nums, int m){

	int lowest_sum = *max_element(nums.begin(), nums.end());
	int max_sum = accumulate(nums.begin(), nums.end(), 0) + 1;

	while(lowest_sum < max_sum){
		int guessed_sum = lowest_sum + (max_sum - lowest_sum)/2;
		if (isValid(nums , m, guessed_sum))
			max_sum = guessed_sum;
		else
			lowest_sum = guessed_sum+1;
		
	}

	return lowest_sum;
}

};