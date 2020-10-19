class Solution {
public:
   //76 
//minimum window substring


string minWindow(string s, string t){
	//it can contain small chars also
    if(s.size() < t.size())
        return "";
	vector <int> count(256,-1);
	vector <set <int>> indices(256);
	
    int l=-1,r=-1;
    int smallest = INT_MAX; 
    
	for (int i=0;i<t.size();i++){
		int ind = t[i];
		if (count[ind]==-1){ //first occourence
			count[ind] = 1;
		}else
			count[ind]++;
	}
		
	for (int i=0;i<s.size();i++){
		int ind = s[i];
		if (count[ind]!=-1){
			if(count[ind] > 0){
				count[ind]--;
				indices[ind].insert(i);
                
			}else{// count ==0
				//delete first
                indices[ind].erase(indices[ind].begin());
				indices[ind].insert(i);
				
			}
            
            int sum=0;
				int mn=INT_MAX;
				int mx=INT_MIN;
				for (int j=0;j<256;j++){
					if (count[j]!=-1){
						sum += count[j];
                        if(indices[j].size()>0) {
						int  lo= *(indices[j].begin());
                        int hi = *(indices[j].rbegin());
						if (lo < mn){
                        
							mn = lo;
						}
                        if(hi > mx){
							mx = hi;
						}
                        }
					}
				}       
				if(sum==0){
                            
					if ((l==-1 && r==-1) || r-l > mx-mn){
						r = mx;
						l = mn;
					}
				}
            
		}
	}
    if(r==-1 && l==-1) 
        return "";
	return s.substr(l, r-l+1);
}

};