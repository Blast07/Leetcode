class Solution {
public:
          
bool canJump(vector<int>& nums){
    int n=nums.size();
    int min_steps = 1;
    for(int i=n-2;i>=0;i--){
        if(nums[i]>=min_steps){
            min_steps =1;
        }else{     
            min_steps++;
        }            
    } 
    return min_steps==1?1:0;
    
}

};