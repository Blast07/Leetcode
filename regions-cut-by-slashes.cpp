//959

int regionsBySlashes(vector<string>& grid) {
	
	int n = grid.size();
	vector <vector <int>> G(2*n, vector <int> (2*n,0));

	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			
			int r = 2*i;
			int c = 2*j;

			if (grid[i][j] == '/'){
				G[r][c+1] = 1; //1 represents forward slashes
				G[r+1][c] = 1; 
			}
			else if(grid[i][j] == '\\'){
				G[r][c] = 2; //2 represents backward slashes
				G[r+1][c+1] = 2;
			}
		}
	}

	
	int res = 0;

	vector <vector <int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};

	for (int i=0;i<2*n;i++){
		for (int j=0;j<2*n;j++){
			if (!G[i][j]){
				res++;
				vector <pair<int, int>> st;
				st.push_back({i,j});
				G[i][j] = 1; //marking visited

				while(!st.empty()){
					auto top = st.back(); st.pop_back();	

					int x,y;

					for (auto d:dir){
						x = top.first + d[0];
						y = top.second + d[1];
                        
						if ((x >= 0 && x<2*n) && (y>=0 && y<2*n) && !G[x][y]){
							st.push_back({x,y});
							G[x][y] = 1;
						}
					}

					//main diagonal {{-1,-1}, {1,1}}
					//we can move along the main diagonal if there are no forward slashes
					x = top.first - 1;
					y = top.second - 1;

					if((x >= 0 && x<2*n) && (y>=0 && y<2*n)){
						if (!G[x][y] && G[x][y+1] !=1 && G[x+1][y] != 1){
							st.push_back({x,y});
							G[x][y] = 1;
						}
					}

					x = top.first + 1;
					y = top.second + 1;

					if((x >= 0 && x<2*n) && (y>=0 && y<2*n)){
						if (!G[x][y] && G[x][y-1] !=1 && G[x-1][y] != 1){
							st.push_back({x,y});
							G[x][y] = 1;
						}
					}
					
					//second diagnol {{-1,1}, {1,-1}}
					//we can move along the second diagnol if there are no backward slashes
					x = top.first - 1;
					y = top.second + 1;

					if((x >= 0 && x<2*n) && (y>=0 && y<2*n)){
						if (!G[x][y] && G[x][y-1] !=2 && G[x+1][y] != 2){
							st.push_back({x,y});
							G[x][y] = 1;
						}
					}

					x = top.first + 1;
					y = top.second - 1;

					if((x >= 0 && x<2*n) && (y>=0 && y<2*n)){
						if (!G[x][y] && G[x][y+1] !=2 && G[x-1][y] != 2){
							st.push_back({x,y});
							G[x][y] = 1;
						}
					}
					
				}
			
			}
		}
	}

	return res;

}
