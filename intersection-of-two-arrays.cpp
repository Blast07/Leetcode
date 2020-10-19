class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size()==0)
            return vector<int>();
        int max1=INT_MIN;
        int max2=INT_MIN;
        vector <int> intersection;
        for (int i=0;i<nums1.size();i++){
            if (nums1[i]>max1)
                max1 = nums1[i];
        }
        
        for (int i=0;i<nums2.size();i++){
            if (nums2[i]>max2)
                max2 = nums2[i];
        }
        
        int m = max(max1,max2);
        int visited[m+1] = {0};
        for (int i=0;i<nums1.size();i++)
            visited[nums1[i]] = 1;
        
        for (int i=0;i<nums2.size();i++){
            if (visited[nums2[i]]){
                intersection.push_back(nums2[i]);
                visited[nums2[i]] = 0;
            }
            
        } 
        return intersection;
    }
};