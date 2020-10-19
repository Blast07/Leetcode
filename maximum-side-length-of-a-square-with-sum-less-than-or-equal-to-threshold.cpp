class Solution {
public:
    bool isValid(vector <vector <int>> &vsum, int m, int threshold){
	for (int i=1;i<=vsum.size()-m;i++){
		for (int j=1;j<=vsum[0].size()-m;j++){
			int x = i + m-1;
			int y = j + m-1;
			int sum = vsum[x][y] - vsum[x][y-m] - vsum[x-m][y] + vsum[x-m][y-m];
			if (sum<=threshold)
				return true;
		}
	}

	return false;
}

int maxSideLength(vector <vector <int>> &mat, int threshold){

	vector <vector <int>> vsum(mat.size()+1 , vector <int> (mat[0].size()+1,0));

	
	for (int i=1;i<=mat.size();i++){
		for (int j=1;j<=mat[0].size();j++){
			vsum[i][j] = vsum[i][j-1] + vsum[i-1][j] - vsum[i-1][j-1] + mat[i-1][j-1];
		}
	}

	int l = 1;
	int r = min(mat.size(), mat[0].size());

	int ans = 0;

	while(l<=r){
		int m = l + (r-l)/2;	

		if (isValid(vsum, m, threshold)){
			ans = m;
			l = m+1;
		}else{
			r = m-1;
		}

	}

	return ans;
}

};