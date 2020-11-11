//853

//cars that reach destination in same time wil be in same fleet
//remember a car can on never cross  the car in front of it
int carFleet(int target, vector<int>& position, vector<int>& speed) {
	vector <pair<int, int>> v;
	for (int i=0;i<position.size();i++){
		v.push_back({position[i], speed[i]});
	}

	sort(v.begin(), v.end()); //sort according to posiiton
	
	int res = 0;
	float t = -1;
	for (int i=speed.size()-1;i>=0;i--){
		float time = ((float)target - v[i].first)/speed;

		if (time == t)
			continue;
		else if(time > t){
			res++;
			t = time;
		}
	}

	return res;
}
