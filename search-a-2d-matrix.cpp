class Solution {
public:
bool searchMatrix(vector <vector <int>> &matrix, int target){
	
	int m = matrix.size(), n; 
        
    if (m)
        n = matrix[0].size();
    if (!n)
        return false;

        
	int l = 0, r = m - 1;

	int row = -1;

	while(l<=r){
		int mid = l + (r-l)/2;

		if (matrix[mid][n-1] == target)
			return true;
		else if (matrix[mid][n-1] > target){
			row = mid;
			r = mid -1;
		}else
			l = mid+1;
	}

	if (row == -1)
		return false;
	
	l =0, r = n-1;

	while(l<=r){
		
		int mid = l + (r-l)/2;

		if (matrix[row][mid] == target)
			return true;
		else if (matrix[row][mid] > target){
			r = mid -1;
		}else
			l = mid+1;
        
	}
	
	return false;

}


};