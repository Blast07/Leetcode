class Solution {
public:
int f(vector <int> &ar, int k){
	//returns number of subarrays which have atmost k diff integers
	
	int left = 0;
	int right = 0;
	int count = 0;

	unordered_map <int,int > m;
	while(right < ar.size()){
		m[ar[right]]++;
		while(m.size()>k){
			m[ar[left]]--;
			if(m[ar[left]]==0)
				m.erase(ar[left]);
			left++;
		}

		count += right - left + 1;
		right++;
	}
	return count;


}

int subarraysWithKDistinct(vector<int>& A, int k) {
  return f(A,k) - f(A,k-1);
}



};