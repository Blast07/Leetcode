//1361

bool dfs(int root, vector <int> &leftChild, vector <int> &rightChild, vector <int> &in){
	if (root == -1)
		return true;
	else if (in[root] == 0){ //already visited
		return false;
	}else{
		in[root]  = 0; //make it visited
		return dfs(leftChild[root], leftChild, rightChild, in) && dfs(rightChild[root], leftChild, rightChild, in);
			
	}
}

bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
	vector <int> in(n,0);

	for (int i=0;i<n;i++){
        
        if (leftChild[i]!=-1)
		    in[leftChild[i]]++;
        
        if (rightChild[i]!=-1)
		    in[rightChild[i]]++;
	}

	int root = -1;

	for (int i=0;i<n;i++){
		if (in[i] > 1)
			return false;
		else if(in[i] == 0){
			if (root!=-1)
				return false;
			root = i;
		}
	}

	if (root == -1)
		return false;

	//using in as visited
	in[root] = 1; //1 - not visited, 0 visited
	if (!dfs(root, leftChild, rightChild, in))
		return false;

	for (int i=0;i<n;i++){
		if (in[i])
			return false;
	}

	return true;
}
