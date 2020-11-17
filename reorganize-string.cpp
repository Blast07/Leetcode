//767

//Take the top two most occuring chars
string reorganizeString(string S) {
	vector <int> count(26, 0);
	for (char s:S){
		count[s - 'a']++;	
	}
	priority_queue <pair<int, char>> pq;
	for (int i=0;i<26;i++){
		if (count[i]){
			pq.push({count[i], 'a'+i});	
		}
	}
	
	string res = "";
	while(pq.size() > 1){
		auto first_maxp = pq.top(); pq.pop(); 
		auto second_maxp = pq.top(); pq.pop(); 
		
		res.push_back(first_maxp.second); first_maxp.first--;
		res.push_back(second_maxp.second); second_maxp.first--;

		if (first_maxp.first)
			pq.push(first_maxp);

		if (second_maxp.first)
			pq.push(second_maxp);

	}

	if (pq.size()){
		if (pq.top().first > 1)
			return ""; //not possible
		res.push_back(pq.top().second);	
	}

	return res;

}
