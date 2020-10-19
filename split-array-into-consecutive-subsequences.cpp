class Solution {
public:
  bool isPossible(vector <int> &nums){
	map <int,int> mp;	
	for (int num:nums)
		mp[num]++;	
		
	while(!mp.empty()){
		auto it = mp.begin();

		int prev = it->first;
		int prev_count = --it->second;
		it++;

		if (prev_count  == 0)
			mp.erase(prev);

		int k = 1;

		for (;it!=mp.end();it++){
			if (it->first==prev + 1 && it->second > prev_count  ){
				k++;
				prev = it->first;
				prev_count = --it->second;
				if (prev_count == 0 )
					mp.erase(prev);
				
			}else{
				if (k<3)
					return false;
				else{
					break;
				}
			}

				
		}
		if (k<3)
			return false;

	}
	return true;

}

};