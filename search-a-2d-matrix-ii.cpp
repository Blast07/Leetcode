class Solution {
public:
    bool searchMatrix(vector <vector <int>> &matrix, int target){
    if (!matrix.size())	
        return false;
	//start from top right corner element
	//because all elements that are >= than that , are below it
	//elements that are smaller than are on left

	int i = 0;
     
	int j = matrix[0].size()-1;

	while( i<matrix.size() && j>=0 ){
		if (matrix[i][j] == target)	
			return true;
		else if(matrix[i][j] > target)
			j--;
		else
			i++;
	}

	return false;

}

};