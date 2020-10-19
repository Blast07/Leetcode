class Solution {
public:
    
    

bool canReach(vector<int>&arr,int i,vector <bool> &visited){
    if(i<0 || i>=arr.size() || visited[i]){
        return false;
    }else{
        if(arr[i]==0)
            return true;
        visited[i] = true;
        return canReach(arr,i+arr[i],visited) || canReach(arr,i-arr[i],visited);
    }
    
}

bool canReach(vector<int>& arr, int start) {
    bool no_zero =true;
    
    for (int x:arr){
        if(!x){
            no_zero =false;
            break;
        }
    }
    if(no_zero)
        return false;
        
    vector <bool> visited(arr.size(),false);
    return canReach(arr,start,visited);    
    
}

};