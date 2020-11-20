//399

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	unordered_map <string, vector <pair <string, double>>> G;

	for (int i=0;i<equations.size();i++){
		G[equations[i][0]].push_back({equations[i][1], values[i]});
		G[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
	}
	
	unordered_set <string> visited;
	vector <pair <string, double>> st;
	vector <double> res;

	for (auto query:queries){
        if ((G.find(query[0]) == G.end()) || (G.find(query[1]) == G.end())){
            res.push_back(-1.0);
            continue;
        }
        if (query[0] == query[1]){
            res.push_back(1.0);
            continue;
            
        }
		visited.clear();
		st.clear();
        
		st.push_back({query[0], 1});
		visited.insert(query[0]);

		bool flag = false;

		while(!st.empty()){

			auto top = st.back(); st.pop_back();

			for (auto p:G[top.first]){

				if (visited.find(p.first) == visited.end()){	

					visited.insert(p.first);
					double val = top.second * p.second;
					st.push_back({p.first, val});

					if (p.first  == query[1]){
						res.push_back(val);							
						flag = true;
						break;
					}	
				}
			}

			if (flag)
				break;
		}
		if (!flag)
			res.push_back(-1.0);
	}

	return res;

}
