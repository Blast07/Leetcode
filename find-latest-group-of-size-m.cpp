//1562

int findLatestStep(vector<int>& arr, int m) {
	int n = arr.size();
	if (m == n)
		return n;

	set <int> s;
	s.insert(0); s.insert(n+1); //putting 0 at 0 and n+1

	for (int i = n-1; i >0;i--){
		s.insert(arr[i]);
		auto it = s.find(arr[i]);
		int next_zero = *(++it); it--;
		int prev_zero = *(--it); it--;

		if (arr[i] - prev_zero - 1 == m || next_zero - arr[i] -1 == m)
			return i;
	}

	return -1;
}
