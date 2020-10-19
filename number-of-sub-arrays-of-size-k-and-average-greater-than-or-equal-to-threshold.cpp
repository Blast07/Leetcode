class Solution {
public:
    int numOfSubarrays(vector <int> &arr, int k, int threshold){

	int res = 0,i =0;
	int sum = 0;
	for (;i<k;i++){
		sum += arr[i];
	}
	if(sum/k >= threshold)
		res++;
	for (;i<arr.size();i++){
		sum -= arr[i-k];
		sum += arr[i];
		if(sum/k >= threshold)
			res++;
	}

	return res;
}

};