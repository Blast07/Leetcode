

int countSetBits(int num){
	int count = 0;
	while(num){
		num = num&(num-1);
		count++;
	}
	return count;

}

bool compareSetBits(int x, int y){

	int countx = countSetBits(x);
	int county = countSetBits(y);
	if (countx == county)
		return x<=y;
	else
		return countx<county;
}

class Solution {
public:

vector <int> sortByBits(vector <int> &arr){
	sort(arr.begin(), arr.end(), compareSetBits);
	return arr;
}


};