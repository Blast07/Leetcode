//638

int f(vector<int> items, vector<vector <int>> &offers, vector <int> &qty, int k){
    
    if (k == offers.size()){
        //no more offers left, calculate direct cost
        int cost = 0;
        for (int i=0;i<items.size();i++)
            cost += qty[i]*items[i];
        return cost;
    }
	bool left = false; //if any items left
	for (int i=0;i<qty.size();i++){
		if (qty[i]){
			left = true;
			break;
		}
	}
	if (!left)
		return 0;	
	else{
        int cost;
        vector <int> costs;    
        costs.push_back(f(items, offers, qty, k+1)); //skipping current offer

        bool applicable = true;
        int j=1;
		while(applicable){	
			
			for (int i=0;i<qty.size();i++){
				if (qty[i] < j*offers[k][i]){
					//not applicable
                    applicable = false;
					break;
				}

			}
            if (!applicable)
                break;
            
            
            //applying offer for j times
			for (int i=0;i<qty.size();i++){
				qty[i] -= j*offers[k][i];
			}
			cost = j*offers[k].back() + f(items, offers, qty, k+1);
            costs.push_back(cost);
                
            for (int i=0;i<qty.size();i++)
                qty[i] += j*offers[k][i];
            
            j++;
            
		}

		return *min_element(costs.begin(), costs.end());
	
	}

}

int shoppingOffers(vector <int> &items, vector<vector <int>> &offers, vector <int> &qty){	
	return f(items, offers, qty, 0);
	
}
