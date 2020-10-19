class Solution {
public:
    map <pair<int,int>,int>  mem;
    
    int findTotalWays(vector <int> &nums, int i, int target,int till_now){
        if(i==nums.size()){
            if(till_now==target)
                return 1;
            return 0;
        }else if(mem.find(make_pair(i,till_now))!=mem.end()){
            return mem[make_pair(i,till_now)];
        }
        else{
            int plus = findTotalWays(nums,i+1,target,till_now + nums[i]);
            int minus = findTotalWays(nums,i+1,target,till_now - nums[i]);
            mem[make_pair(i,till_now)] = plus+minus;
            return mem[make_pair(i,till_now)];
        }
    }
    /*
    void findTotalWays(vector <int> &nums,int i,int target,int till_now,int &total_ways){
        if (i==nums.size()){
            if(till_now==target)
                total_ways++;
        }else{
            findTotalWays(nums,i+1,target,till_now+nums[i],total_ways);
            findTotalWays(nums,i+1,target,till_now-nums[i],total_ways);
                
        }
    }*/
    int findTargetSumWays(vector<int>& nums, int S) {
        
        return findTotalWays(nums,0,S,0);
        
    }
};