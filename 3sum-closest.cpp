class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        for (int i=0;i<nums.size();i++){
            int sum = target - nums[i];
            int start = i+1;   int end = nums.size()-1;
            
            while(start < end){
                int temp = nums[start] + nums[end];
                if (temp == sum){
                    min_diff = 0;
                    break;
                }else if(temp > sum){
                    if (temp - sum < abs(min_diff))
                        min_diff = sum-temp;
                        
                    end--;
                }else{
                    if (sum-temp < abs(min_diff))
                        min_diff = sum-temp;
                    start++;
                }
            }
            if (min_diff == 0)
                break;
                
        }
        return target - min_diff;
        
    }
};