class Solution {
public:
bool findminFibs(vector <int> &fibs, int k, int i, int &res){
	if (k==0)
		return true;
	else if(k<0 || i<0)
		return false;
	else{
		if (findminFibs(fibs,k-fibs[i],i,res)){
			res++;
            return true;
		}else
			return findminFibs(fibs, k, i-1, res);
	}
}

int findMinFibonacciNumbers(int k){
	int res = 0;
	vector <int> fibs;
	fibs.push_back(1);
	fibs.push_back(1);

	int i = 1;
	while(fibs[i-1] + fibs[i] <= k){
		fibs.push_back(fibs[i-1] + fibs[i]);	
		i++;
	}
	findminFibs(fibs, k, i, res);

	return res;
}

};