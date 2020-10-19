class Solution {
public:
    
    //better solution
//if a == b, then a ^ b == 0.

//Starting from arr[i], xor arr[i + 1], arr[i + 2], ..., arr[k], until we get 0, 
//then j can be any index between (i, k]. Note that we don't need 3 numbers to make arr[i] ^ arr[j] ^ arr[k] == 0 
//since j <= k (arr = [1, 1], answer = 1, when i = 0, j = 1, k = 1).

    int countTriplets(vector<int>& arr) {
    int res = 0;
    for (int i = 0, stop = arr.size(); i < stop; ++i) {
      int num = 0;
      for (int j = i; j < stop; ++j) {
        num ^= arr[j];
        if (num == 0 && (j - i) > 0) res += (j - i);
      }
    }
    return res;
  }

    /*
int countTriplets(vector <int> &arr){
	
	if (arr.size()<2)
		return 0;

	int res = 0;
	int a = 0;
	int prev = 0;
	int b = 0;

	for (int i=0;i<arr.size()-1;i++){
		a^= arr[i];
		prev =0;
		for (int j=i+1;j<arr.size();j++){
			b = 0;
			prev ^= arr[j];
			for(int k=j;k<arr.size();k++){
				b^=arr[k];
				if (a==b)
					res++;

			}
			a ^= arr[j];
		}
		a ^=prev;
		a ^= arr[i];
	}	
	return res;
	
}
*/



};