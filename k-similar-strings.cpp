//854

int kSimilarity(string a, string b) {
	
	queue <pair<string, int>> q;
	unordered_set <string> visited;

	q.push({a, 0});

	visited.insert(a);

	while(!q.empty()){
		auto front = q.front(); q.pop();

		if (front.first == b)
			return front.second;

		//generate neghbors

		int i =0;
		while(front.first[i] == b[i])
			i++;

		for (int j=i+1;j<a.size();j++){
			string temp = front.first;
            if (b[j] == temp[i] && b[j] != temp[j]){
			    swap(temp[i], temp[j]);
			    if (visited.find(temp) == visited.end()){
				    q.push({temp, front.second+1});
				    visited.insert(temp);
			    }
            }
		}
	}

	return 0;//dummy return;
}
