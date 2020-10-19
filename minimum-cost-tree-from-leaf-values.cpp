class Solution {
public:
  int mem[41][41];
  
    int max_(vector <int> &arr,int start, int end){
	if(start<=end){
		int m = INT_MIN;
		for (int i=start;i<=end;i++){
			m = max(m,arr[i]);
		}	
		return m;
	}else
		return -1;
}

int minCostTree(vector <int> &arr, int start, int end){
	if(start>=end)
		return 0;
	else if(mem[start][end]!=-1)
		return mem[start][end];
	else{
		int left_max;
		int right_max;
		int cur_sum=0;
		int min_sum=INT_MAX;
		for (int i=start;i<=end;i++){
			cur_sum = 0;
			left_max = max_(arr,start,i);
			right_max = max_(arr,i+1,end);

			if (left_max==-1 || right_max==-1)
				continue;
			cur_sum += left_max*right_max;
			cur_sum += minCostTree(arr, start, i);
			cur_sum += minCostTree(arr, i+1, end);
			min_sum = min(cur_sum,min_sum);

		}
		mem[start][end] = min_sum;
		return min_sum;
	}
}


    int mctFromLeafValues(vector<int>& arr) {
       	for (int i=0;i<41;i++){
		for (int j=0;j<41;j++){
			mem[i][j]=-1;
		}
	        }
        return minCostTree(arr,0,arr.size()-1);
 
    }
};