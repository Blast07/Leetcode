class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size()<=1)
            return 0;
        int left[height.size()];
        int right[height.size()];
        
        right[height.size()-1] = height[height.size()-1];
        for (int i=height.size()-2;i>0;i--)    
            right[i] = max(height[i],right[i+1]);
        
        left[0] = height[0];
        for (int i=1;i<height.size()-1;i++)
            left[i] = max(height[i],left[i-1]);
        
        int water=0;
        for (int i=1;i<height.size()-1;i++)
            water += min(left[i],right[i]) - height[i];
        
        return water;
    }
};