class Solution {
public:
int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map <int , int> mp;
    
    for (int num:arr)
        mp[num]++;
    
    vector <int> counts;
    for (auto it:mp)
        counts.push_back(it.second);
    
    sort(counts.begin(), counts.end());
    int ans = counts.size();
    if (k==0)
        return ans;
    
    for (int count:counts){
        if (count <= k ){
            ans--;
            k-=count;
        }else
            break;
    }
    
	return ans;
}

};