class Solution {
public:
    
    bool DFS(vector <int> &nums,vector <bool> &visited,int ind,int len,int sum){
        sum += nums[ind];
        if(sum == len){
            visited[ind] = true;
            return true;
        }else if(sum > len)
            return false;
        else{
            for (int i=ind+1;i<nums.size();i++){
                if(!visited[i] && DFS(nums,visited,i,len,sum)){
                    visited[ind] = true;
                    return true;
                }
            }
            return false;
        }
    }
    
    bool makesquare(vector<int>& nums) {
        if(!nums.size())
            return false;
        int perimeter=0;
        for (int i=0;i<nums.size();i++)
            perimeter += nums[i];
        int len = perimeter/4;
        int sides =0;
        vector <bool> visited(nums.size(), false);
        
                sort(nums.begin(),nums.end(),greater<int>());

        for(int i=0;i<nums.size() && sides<4;i++){
            if(!visited[i]){
                if(DFS(nums,visited,i,len,0))
                    sides++;
                else return false;
            }
        }
        for (int i=0;i<visited.size();i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};