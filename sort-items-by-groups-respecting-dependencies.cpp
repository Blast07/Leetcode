//1203

bool DFS(int i, vector <vector <int>> &before_item,
		 unordered_map <int,int> &visited, vector <bool> &item_added, vector<int> &res){
	
	if (visited[i] == 1){//cycle
		return false;
	}else if (visited[i] == 2){
		return true;
	}
	visited[i] = 1;
	for (int b_it: before_item[i]){
		if (!DFS(b_it, before_item, visited, item_added,res))
			return false;
	}

	visited[i] =2;
	if (!item_added[i]){
		res.push_back(i);
		item_added[i] = true;	
	}

	return true;
	
}

bool DFS_items(vector <int> &items, vector <vector <int>> &before_item, vector <bool> &item_added,vector <int> &res){
	unordered_map <int,int> visited;
	for (int i:items){
		if(!DFS(i, before_item,visited, item_added,res))
			return false;
	}
	return true;
}

bool DFS_group(int g, vector <vector <int>>&before_group,vector <vector <int>> &before_item, 
		 vector <vector <int>> &G,vector <int> &group_visited, vector <bool> &item_added,vector <int> &res){
	//cout<<g<<" "<<G.size()<<endl;
    if (group_visited[g] == 1){//cycle
		return false;
	
	}else if(group_visited[g] == 2) //completely traversed
		return true;
	
    //cout<<"beforee group"<<endl;
        
	group_visited[g] = 1; //being traversed 
	
	for (int gb: before_group[g]){
		if (!DFS_group(gb, before_group, before_item, G, group_visited,  item_added,res)){
			return false;
		}
	}

	if (!DFS_items(G[g], before_item, item_added,res))
		return false;

	group_visited[g] = 2;
	return true;
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& before_item) {
	
	vector <vector <int>> G(m);
	vector <bool> in(n, 0);
    
    //cout<<"G"<<endl;
	for (int i=0;i<n;i++){
		if (group[i] == -1){
			//creating a diff group for item which does not 
			//belong to any group
			group[i] = m++;
			G.push_back({i});	
		}	
		else{
			G[group[i]].push_back(i);
		}
	}
    //cout<<"here"<<endl;
    vector <vector <int>> before_group(m);

	for (int i=0;i<n;i++){
		for (auto item:before_item[i]){
			if (group[item] != group[i]){
				//graph_adj[group[item]].push_back(group[i]);
				before_group[group[i]].push_back(group[item]);
			}
			//in[i] = true;
		}
	}
    //cout<<"hee11"<<endl;
	vector <int> res;
	vector <int> group_visited(m,0);
	vector <bool> item_added(n, false);

	for (int g=0;g<m;g++){
        //cout<<g<<endl;
		if (!DFS_group(g, before_group, before_item, G, 
			group_visited, item_added, res)){
				return {};
			}
	}

	return res;

}
