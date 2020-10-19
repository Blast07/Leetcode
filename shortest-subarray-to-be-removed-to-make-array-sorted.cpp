class Solution {
public:
int findLengthOfShortestSubarray(vector <int> &arr){

	int i=0;
	while(i<arr.size()-1 && arr[i+1] >= arr[i])
		i++;

	if (i == arr.size()-1)
		return 0;

	int j = arr.size()-1;
	while(j >0 && arr[j] >= arr[j-1])
		j--;

	int n = arr.size();
    int res = min(n-i-1 , j);

	//merge two sorted arrays
	for (int r=0;r<=i;r++){
		if (arr[r] <= arr[j])
			res = min(res, j-r-1);
		else if(j < arr.size()-1)
			j++;
		else
			break;
	}
	return res;
}

};