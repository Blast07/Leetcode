class Solution {
public:
    int getWinner(std::vector <int> &arr, int k){
	if (k>=arr.size())
		return *std::max_element(arr.begin(), arr.end());

	int i=0;
	int max = arr[i];
	while(i<arr.size()){
		int score = 0;
		if (i && max < arr[i]){
			score++;
			max = arr[i];
		}	
		int temp = i;
		while(i+1<arr.size() &&  arr[temp] > arr[i+1]){
			i++;
			score++;
		}
		if (temp == i)
			i++;
		if (score >= k){
			return arr[temp]; 
		}
	}
	return max;

    }


};