//1546

int maxNonOverlapping(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    int prev = INT_MIN; //ending of previous array with target sum
    int sum = 0;
    mp[0] = -1;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (mp.count(sum - target) && prev <= mp[sum - target] ) {
            res++;
            prev = i;
        }
        mp[sum] = i;
    }
    return res;
}
