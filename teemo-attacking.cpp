class Solution {
public:
int findPoisonedDuration(vector <int>&timeSeries, int duration){
	int res = 0;
	int poisoned_till = -1;
    int prev;
	for (int time:timeSeries){
		if (time > poisoned_till){
			res += duration;
			poisoned_till = time + duration - 1;	
		}
		else{
			
			res += time-prev;
			poisoned_till+=time-prev;
		}
        prev = time;

	}
	return res;
}

};