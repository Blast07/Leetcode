//996

bool perfectSquare(int a){
	int res = sqrt(a);
	return res*res == a;
}

void squarePerms(int prev_i, vector <int> &temp,vector <bool> &taken, set <vector <int>> &visited, vector <int> &A){
	
	if (temp.size() == A.size()){
		visited.insert(temp);
	}else{
		unordered_set <int> s;
		for (int i=0;i<A.size();i++){
			if (!taken[i] && perfectSquare(A[i] + A[prev_i]) && (s.find(A[i])==s.end())){
				
				s.insert(A[i]);
				taken[i] = true; temp.push_back(A[i]);
				squarePerms(i,temp , taken, visited, A);
				taken[i] = false; temp.pop_back();

			}
		}
	}

}

int numSquarefulPerms(vector<int>& A) {
	int n = A.size();
	if (n == 1)
		return perfectSquare(A[0]);
	set <vector <int>> visited;	
	vector <bool> taken(n,false);
	vector <int> temp;

	for (int i=0;i<n;i++){
		taken[i] = true; temp.push_back(A[i]);
		squarePerms(i, temp, taken, visited, A);
		taken[i] = false; temp.pop_back();
	}
	
	return visited.size();


}
