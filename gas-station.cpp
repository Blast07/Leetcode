class Solution {
public:
    int canCompleteCircuit(vector <int>&gas, vector<int> &cost){
    int total=0;
    int start=-1;
    int temp = 0;
    
    for(int i=0;i<gas.size();i++){
        int diff = gas[i]-cost[i];
        if (start == -1){
            if(diff>=0){
                start = i;
                temp = diff;
            }
        }else{
            temp +=diff;
            if (temp <0){
                temp = 0;
                start =-1;
            }
        }
        total+=diff;
    }
    if (total <0)
        return -1;
    else 
        return start;
}
        

};