class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector <int> sums;
        for(int i=0;i<nums.size();i++){
               int sum = 0;
               for (int j=i;j<nums.size();j++){
                   sum += nums[j];
                   sums.push_back(sum);
               }
            
        }
        sort(sums.begin(), sums.end());
        const unsigned int M = 1000000007;
                   
        int res = 0;
        for (int i=left-1;i<=right-1;i++)
            res = (res+sums[i])%M;
        return res;
    }
};