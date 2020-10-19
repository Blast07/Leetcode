class Solution {
public:
    int pass[3];
    int mem[366][366];
    Solution(){
        pass[0] = 1;
        pass[1] = 7;
        pass[2] = 30;
    }
int minCostTickets(vector <int> &days,vector <int> &costs, int i, int expiry){
	if(i>=days.size())
		return 0;
	else if(mem[i][expiry]!=-1)
		return mem[i][expiry];
	else{
		if (days[i]>expiry){
			int min_cost = INT_MAX;
			int cost;
			for (int j=0;j<costs.size();j++){
				cost = costs[j];
                expiry = days[i]+pass[j]-1;
                expiry = expiry<=365 ? expiry : 365;
				cost += minCostTickets(days, costs, i+1, expiry);
				min_cost = min(min_cost, cost);
			}
			mem[i][expiry] = min_cost;
			return min_cost;
		}else{
			mem[i][expiry] = minCostTickets(days, costs, i+1, expiry);  
			return mem[i][expiry];
		}
	}
}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
       for (int i=0;i<366;i++){
		for (int j=0;j<366;j++){
			mem[i][j] = -1;
		}
       }  
       return minCostTickets(days,costs,0,0);

    }
};