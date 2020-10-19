class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        
        int start = nums[0];
        while(start != slow){
            slow = nums[slow];
            start = nums[start];
            if (slow == start)
                break;
        }
        
        return start;
    }
};