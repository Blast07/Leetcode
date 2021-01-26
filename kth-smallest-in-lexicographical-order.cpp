//440

int countSteps(long int left,long int right,long int n){
	int steps = 0;
	while(left <= n){
		steps += min(n+1, right) - left;
		left *= 10;
		right *= 10;
	}

	return steps;
}

int findKthNumber(int n, int k){
	int cur = 1;
	k--;

	while(k > 0){
		int steps = countSteps(cur, cur+1, n);
		if (steps <= k){
			cur++;
			k -= steps;
		}else{
			cur *= 10;
			k--;
		}
	}

	return cur;
}

//simple DFS solution - timeout
//int findKthNumber(int n, int k) {
//
//	int temp_k = 0;
//	stack <long int> st;
//
//	for (int i=9;i>0;i--)
//		st.push(i);
//
//	while(!st.empty()){
//		long int top = st.top(); st.pop();
//		temp_k++;
//
//		if (temp_k == k)
//			return top;
//
//		for (int i=9;i>=0;i--){
//			int long child = top*10 + i;
//			if (child <= n)
//				st.push(child);
//		}
//	}
//
//	return -1; //dummy return
//}
