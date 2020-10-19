class Solution {
public:
    int numRescueBoats(vector <int> &people, int limit){
	sort(people.begin(), people.end());
	int i=0;
	int j=people.size()-1;
	int res =0;

	while(i<=j){
		if(i==j){
			res++;
			break;
		}

		if(people[i] + people[j] <=limit ){
			res++;
			i++;
			j--;
		}else{
			if(limit - people[i] < people[i]){
				//cannot be paired
				res++;
				i++;
			}
			
			if (limit - people[j] < people[i]){
				//cannot be paired
				res++;
				j--;
			}
			// ? what if both thsese conditions are false ? infinite loop
		
		
		}
	
	}

	return res;
}

};