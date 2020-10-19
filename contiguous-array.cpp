class Solution {
public:
 int findMaxLength(vector<int>& nums) {
    int n=nums.size();
    //prefix sum
    
    unordered_map <int,int> first_oc;
    int answer =0;
    int prefix =0;
    first_oc[0] = 0;
    for (int i = 0;i<n;i++){
        prefix += (nums[i]) ? 1:-1;
        if (first_oc.find(prefix)!=first_oc.end())
        answer=max(answer,i+1-first_oc[prefix]);
        else
            first_oc[prefix] = i+1;
    }
    return answer;
}};