class Solution {
public:
    int minCostClimbingStairsUtil(vector <int> stairs, int cur, vector <int> &m){
	if (cur==stairs.size())
		return 0;
	else if(cur>stairs.size())
		return INT_MAX;
	else if(m[cur]!=-1)
		return m[cur];
	else{
		m[cur] = stairs[cur] + min(minCostClimbingStairsUtil(stairs,cur+1,m),
                			     minCostClimbingStairsUtil(stairs,cur+2,m));
		return m[cur];

	}
}
    int minCostClimbingStairs(vector<int>& cost) {
        vector <int> m(cost.size(),-1);
        int minCost = min(minCostClimbingStairsUtil(cost,0,m),
					  minCostClimbingStairsUtil(cost,1,m));
        return minCost;
    }
};