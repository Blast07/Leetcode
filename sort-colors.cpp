class Solution {
public:
    void sortColors(vector<int>& nums) {
       int first=0;
       int last =nums.size()-1;
       int i=0;
       while(first<last && i<=last) {
          if(nums[first]==0 || nums[last]==2){
              if(nums[first]==0){
                  first++;
                  i=first;
              }
              if(nums[last]==2)
                  last--;
          } 
          else{
             if (nums[i]==0){
                  swap(nums[i],nums[first]);
                  first++;
                  if(nums[i]==2 && first<last){
                      swap(nums[i],nums[last]);
                      last--;
                  }
              }else if(nums[i]==2){
                  swap(nums[i],nums[last]);
                  last--;
                  if(nums[i]==0 && first<last){
                      swap(nums[i],nums[first]);
                      first++;
                  }
              }
              i++;
          }
       }
    }
};