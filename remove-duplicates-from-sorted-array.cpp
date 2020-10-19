class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0 ||nums.size()==1)
            return nums.size();
        
        int vacant = 1;
        int i=1;
        while(i<nums.size()){
            if (nums[i]!=nums[i-1])            
                nums[vacant++] = nums[i];
            i++;
        }
        return vacant;
       
    }
};