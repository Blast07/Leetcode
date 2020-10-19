class Solution {
public:
bool isPossibleDivide(vector <int> &nums, int k){
	
	int n =	nums.size(); 
    map <int,int> mp;
    
    for (int i=0;i<n;i++)
        mp[nums[i]]++;
    
    while(!mp.empty()){
        pair <int,int> front = *(mp.begin());
        for (int i=0;i<k;i++){
            if (mp[front.first+i] <=0 )
                return false;
            mp[front.first + i]--;
            if (mp[front.first + i] == 0 )
                mp.erase(front.first + i);
        }
        
    }
    
    return true; 
    

}


};