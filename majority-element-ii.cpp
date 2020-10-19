class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //there can be maximum of only 2 elements in array with count greater than n/3
        //generally num of elements >n/k is k-1;
        vector <int> result;
        int cand1 = 0, cand2 = 1;
        int count1=0, count2 =0;
        for (int i=0;i<nums.size();i++){
            if (nums[cand1]==nums[i]){
                count1++;
                
            }
            else if(nums[cand2]==nums[i]){
                count2++;
            }
            else if (count1==0){
                count1=1;
                cand1 =i;
            }
            else if (count2==0){
                count2=1;
                cand2 = i;
            }else{
                count1--;
                count2--;
            }
        }
        count1 =0;
        count2 =0;
        for (int i=0;i<nums.size();i++){
            if(nums[cand1]==nums[i])
                count1++; 
            else if(nums[cand2]==nums[i])
                count2++;
        }
        if (count1>nums.size()/3)
            result.push_back(nums[cand1]);
        if(count2>nums.size()/3)
            result.push_back(nums[cand2]);
        return result;
    }
};