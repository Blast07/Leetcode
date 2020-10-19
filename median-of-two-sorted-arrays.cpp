class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> temp;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if (nums1[i]<nums2[j])
                temp.push_back(nums1[i++]);
            else
                temp.push_back(nums2[j++]);
        }
        while(j<nums2.size())
            temp.push_back(nums2[j++]);
        
        while(i<nums1.size())
            temp.push_back(nums1[i++]);
        
        int mid = temp.size()/2;
        if(temp.size()%2==0){//even
            double median = (double(temp[mid])+double(temp[mid-1]))/2;
            return median;
        }else{
            return double(temp[mid]);
        }
    }
};