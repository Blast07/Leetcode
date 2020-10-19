class Solution {
public:
    int findPairs(vector <int> &nums, int k){
        if(nums.size()==0 || k<0)
            return 0;
        int res  =0;
        sort(nums.begin(), nums.end());
        if (k==0){
            int i=0;
            int n = nums.size();
            while(i<n-1){
                if (nums[i]==nums[i+1]){
                    res++;
                    
                    while(i<n-1 && nums[i]==nums[i+1]){
                        i++;
                    }
                }
                i++;
            }
            return res;
        }
        for (int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
                continue;
            else{
                for (int j=i+1;j<nums.size();j++){
                      if (nums[j]-nums[i]==k){
                          res++;
                          break;
                      }else if(nums[j]-nums[i]>k)
                          break;
                }
            }
        }
        return res;
        
    }
    /*
    int findPairs(vector<int>& nums, int k) {
        int res =0;
        if (nums.size()==0 || k<0)
            return 0;
        if (k==0){
            unordered_map <int,int> mp;
            for (int num:nums)
                mp[num]++;
            for (auto it = mp.begin();it!=mp.end();it++){
                if (it->second > 1)
                    res++;
            }
            return res;
        }
        
        unordered_set <int>m;
        for (int num:nums)
            m.insert(num);
        for (auto itr = m.begin();itr!=m.end();){
            if(m.find(*itr+k)!=m.end())
                res++;
            if(m.find(*itr-k)!=m.end())
                res++;
            m.erase(itr++);
        }
        return res;
    }*/
    /*
    int findPairs(vector<int>& nums, int k) {
        int res =0;
        if(k<0 || nums.size()==0)
            return 0;
        for (int i=0;i<nums.size()-1;i++){
            bool minus = false;
            bool plus = false;
            bool zero = false;
            if (nums[i]!=INT_MAX){
                for (int j=i+1;j<nums.size();j++){
                    if (nums[j]!=INT_MAX){
                        if(nums[i]==nums[j]){
                            nums[j] = INT_MAX;
                            if (k==0 && !zero){
                                zero = true;
                                res++;
                            }
                        }else if(nums[i]-nums[j]==k && !minus){
                            minus = true;
                            res++;
                        }else if(nums[j]-nums[i]==k && !plus){
                            plus = true;
                            res++;
                        }
                        
                    }
                    
                    
                }
            }
        
        
          }
        return res;
    }*/
};