//840

int mark(int val, vector <bool> &visited){
	if (val >=0 && val <=9)
		visited[val] = true;
	return val;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
	int m = grid.size(), n = grid[0].size();

	if (m < 3 || n < 3)
		return 0;



	int res = 0;	
    

	for (int i=0;i<=m-3;i++){
		for (int j=0;j<=n-3;j++){
            
            vector <int> r(3,0);
	        vector <int> c(3,0);
	        vector <int> d(2,0);
            vector <bool> visited(10,false);
            
			for(int x=0;x<3;x++){
				r[0] += mark(grid[i][j+x], visited);	
				r[1] += mark(grid[i+1][j+x], visited);	
				r[2] += mark(grid[i+2][j+x], visited);	

				c[0] += mark(grid[i+x][j], visited);
				c[1] += mark(grid[i+x][j+1], visited);
				c[2] += mark(grid[i+x][j+2], visited);

				d[0] += mark(grid[i+x][j+x], visited);
				d[1] += mark(grid[i+2 - x][j+x], visited);
			}
			bool flag = true;
			for (int i=1;i<=9;i++){
				if (!visited[i]){
					flag = false;
					break;
				}
			}
			if (!flag)
				continue;

			int prev= r[0];

			for (int val : {r[1],r[2],c[0],c[1],c[2],d[0],d[1]}){
				if (val != prev){
                    flag = false;
                    break;
                }
                prev = val;
				
			}
			if (flag)
				res++;


		} 
	}
	return res;
}
