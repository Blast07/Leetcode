class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();

	vector <vector <int>> diagonals;
    int r=0,c=0;
	for (int d=0;d<n+m-1;d++){
		if (d<m){
			r = m-d-1;
            c=0;
		}else{
            c++;
            r=0;
		}

		vector <int> diagonal;

		int r_temp = r;
		int c_temp = c;
        
		for(;r_temp<m && c_temp<n; r_temp++,c_temp++)
			diagonal.push_back(mat[r_temp][c_temp]);

		sort(diagonal.begin(),diagonal.end());
		
		r_temp = r;
		c_temp = c;

		for(int i=0;r_temp<m && c_temp<n ; r_temp++, c_temp++,i++)
			mat[r_temp][c_temp] = diagonal[i];
		



	}
	return mat;
        
}

};