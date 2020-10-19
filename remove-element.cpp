class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write_index = 0;
        for (int i=0;i<nums.size();i++){
            if(nums[i]!=val)
                nums[write_index++] = nums[i];
        }
        return write_index;
    }
};