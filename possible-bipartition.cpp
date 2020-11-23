//868

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    //vertices starting from 1
	n++;
    
	vector <vector <int>> G(n);

	for (auto dis:dislikes){
		G[dis[0]].push_back(dis[1]);
		G[dis[1]].push_back(dis[0]);
	}

	vector <int> colors(n, -1);
	//-1 not colored
	//0 color 1
	//1 color 2

	queue <int> q;
    
    for (int i=1;i<n;i++){
        if(colors[i]!=-1)
            continue;
	    q.push(i);
	    colors[i] = 0;

        while(!q.empty()){
            int front = q.front(); q.pop();

            for (int j:G[front]){
                if (colors[j] == -1){
                    colors[j] = !colors[front];
                    q.push(j);
                }
                else if(colors[j] == colors[front])
                    return false;
            }
        }
    }

	return true;
}
