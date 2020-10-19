unordered_map <int,int> mycount;
vector <int> myunique;

bool comparator(int num1, int num2){
	return mycount[num1] > mycount[num2];
}



class Solution {
public:

    int minSetSize(vector<int>& arr) {
   	int ans  =0; 
	mycount.clear();
	myunique.clear();

	int n = arr.size();
	for (int i=0;i<n;i++){
		if (mycount.find(arr[i])==mycount.end())
			myunique.push_back(arr[i]);
		mycount[arr[i]]++;
	}
	sort(myunique.begin(), myunique.end(), comparator);
	int size_left = n;	
    for (int i=0;i<myunique.size();i++){
		size_left -= mycount[myunique[i]];
		ans++;
		if (size_left <= n/2)
			break;
	}
	return ans;
}

};