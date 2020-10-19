class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector <vector<int>> triplets; 
        sort(arr.begin(), arr.end());
        int prev = INT_MIN;
        for (int i=0;i<arr.size();i++){
            if (arr[i]==prev)
                continue;
            else{
                int target = -arr[i];
                int s = i+1, e = arr.size()-1;
                while(s<e){
                    if(arr[s] + arr[e] == target){
                        triplets.push_back(vector <int>{arr[i],arr[s],arr[e]});
                        int left = arr[s];
                        int right = arr[e];
                        while(s<arr.size() && arr[s]==left)
                            s++;
                        while(e>0 && arr[e]==right)
                            e--;
                    }else if(arr[s]+arr[e] > target)
                        e--;
                    else
                        s++;
                }
            }
            prev = arr[i]; 
        }
        return triplets;
    }
    
    
};