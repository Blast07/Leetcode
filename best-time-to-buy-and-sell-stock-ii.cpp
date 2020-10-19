class Solution {
public: 
       
    int maxProfit(vector<int> &prices) {
    int mi  = prices[0];
    int ma = INT_MIN;
    int profit = 0;
    for (int i=0;i<prices.size()-1;i++){
        if (prices[i] > prices[i+1]){
            ma = prices[i];
            profit+= prices[i]-mi;
            ma = INT_MIN ;
            mi = prices[i+1];
        }else 
            mi = min(mi,prices[i]);
        
    }
    if (prices[prices.size()-1]>mi)
        profit +=prices[prices.size()-1]-mi;
    return profit;
    
    
}

};