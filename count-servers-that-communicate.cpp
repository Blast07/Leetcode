class Solution {
public:
    int countServers(vector <vector <int>> &grid){
	
	int m = grid.size();
	int n = grid[0].size();
	
	int count = 0;
	for (int i=0;i<m;i++){
		int row_count = 0;
		for (int j=0;j<n;j++){
			if (grid[i][j]){
				row_count++;
			}
		}
		if (row_count > 1){
			count += row_count;
            for (int j=0;j<n;j++){
                if (grid[i][j]){
                    grid[i][j] = 2; //to mark that this has been included
                    //cols[j] = true;
                    
                }
            }
        }
	}

	for (int j=0;j<n;j++){
       int col_count = 0;
       bool flag = false;
       for (int i=0;i<m;i++){
           if (grid[i][j]==1)
               col_count++;
           else if(grid[i][j]==2)
               flag =  true;
       }
       if (flag){
           count += col_count;
       }else{
           if (col_count>1)
               count += col_count;
       }
    }
    return count;
}

};