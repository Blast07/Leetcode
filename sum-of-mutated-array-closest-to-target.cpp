class Solution {
public:
    int findBestValue(vector <int> &arr, int target){
	
	sort(arr.begin(), arr.end());
	vector <int> ps;	

	
	ps.push_back(arr[0]);
	int mx = arr[0];
	for (int i= 1; i<arr.size(); i++){
		ps.push_back(ps.back() + arr[i]);
		mx = max(mx, arr[i]);
	}


	int val = 0;
	int res = 1;
	int diff = INT_MAX;
	int i = 0;
	while(val <=mx  && i<arr.size()){
		for (;i<arr.size();i++){
			if ( arr[i] >=  val){
				int sum = 0;
				if (i-1 >=0 ){
					sum = ps[i-1];
				}
				sum += val*(arr.size() - i);
				if (abs(target - sum) < diff){
					diff = abs(target - sum);
				 	res = val;	
				}
				break;
			}
			
		}
		val++;
	}
	return res;}

};