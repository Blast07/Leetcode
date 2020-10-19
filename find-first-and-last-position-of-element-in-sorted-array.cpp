class Solution {
public:
    int binarySearch(vector <int> &nums,int target,int start,int end){
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                 end = mid-1;
            else
                 start = mid+1;
        }
        return -1;
    }
    int leftBS(vector <int> &nums, int target, int start,int end){
        int ind = binarySearch(nums,target,start,end);
        if(ind==-1)
            return -1;
        else{
            int left = leftBS(nums,target,start,ind-1);
            if(left==-1)
                return ind;
            else
                return left;
              
        }
    }
    int rightBS(vector <int> &nums, int target,int start,int end){
        int ind = binarySearch(nums,target,start,end);
        if (ind==-1)
            return -1;
        else{
            int right = rightBS(nums,target,ind+1,end);
            if (right==-1)
                return ind;
            else
                return right;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       vector <int> res{-1,-1};
       int m = binarySearch(nums,target,0,nums.size()-1);
       if(m==-1)
           return res;
       res[0] = m, res[1] = m;
       int left = leftBS(nums,target,0,m-1);
       cout<<left<<endl; 
       if (left!=-1)
           res[0] = left;
       int right = rightBS(nums,target,m+1,nums.size()-1);
       cout<<right<<endl;
       if(right!=-1)
           res[1] = right;
       
       return res;
    }
};