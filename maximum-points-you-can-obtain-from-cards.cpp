//1423

int maxScore(vector<int>& cardPoints, int k) {
	
	int n = cardPoints.size();
    int res = 0;
	if (k>=n){
		
		for (int i=0;i<n;i++)
			res += cardPoints[i];

		return res;
	}	
	vector <int> pre1(n+2, 0);
	vector <int> pre2(n+2, 0);
	
	int sum =0;
	for (int i=0;i<k;i++){
		sum += cardPoints[i];
		pre1[i+1] = sum;
        //cout<<pre1[i+1]<<endl;
	}

	sum = 0;	
    //cout<<"pre2"<<endl;
	for (int i=n-1;i>=n-k;i--){
		sum += cardPoints[i];
		pre2[i+1] = sum;
        //cout<<pre2[i+1]<<endl;
	}

	res = 0;
    //cout<<"main"<<endl;
	for (int i=0;i<=k;i++){
        //cout<<pre1[i]<<" "<<pre2[n+1-k+i]<<endl;
		res = max(res, pre1[i] + pre2[n+1-k+i]);
	}

	return res;
}
