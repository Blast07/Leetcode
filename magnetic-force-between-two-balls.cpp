class Solution {
public:

bool isValid(vector <int> position, int m, int guessedForce){
	int cumDiff = 0;
	int ans = 0;
	
	for (int i=1;i<position.size();i++){
		cumDiff += position[i] - position[i-1];
		if (cumDiff >= guessedForce){
			ans++;	
			cumDiff = 0;
		}
	}
	return ans >= m-1;
}

int maxDistance(vector <int>&position, int m){
    if (m ==2)
        return *max_element(position.begin(),position.end()) - *min_element(position.begin(),position.end());
	
	sort(position.begin(), position.end());
	int lowestForce = 1;
	int maxForce = position.back() - position[0];

	while(lowestForce<maxForce){
		int guessedForce = lowestForce + (maxForce-lowestForce)/2 + 1;

		if (isValid(position, m, guessedForce))
			lowestForce = guessedForce;
		else
			maxForce = guessedForce-1;
	}
	return lowestForce; 
}


};