class Solution {
public:
int maxSatisfied(vector <int> &customers, vector <int> &grumpy, int X){
	int max_sum = 0;	
	int max_ind = 0; //doubt

	int i = 0, j = 0;
	int n = customers.size();
	int sum = 0;
	while(i < n && !grumpy[i]){
        sum += customers[i];
		i++;
	}
    if (i>=n)
       return sum;
    sum = 0;
	j = i;
	while(i < n && j < n){
		while(j < i + X && j < n){
            if(grumpy[j]) 
			    sum += customers[j];	
            j++;
		}
		if (sum > max_sum){
			max_sum = sum;
			max_ind = i;
		}
        
        
		sum -= customers[i++];
		while(i<n && !grumpy[i]){
			i++;
		}
		if (i > j){
			j = i;
			sum = 0;
		}
	}
    i=0;
    while(i<n){
            max_sum += (!grumpy[i])*customers[i];
        i++;
        
    }
    return max_sum;
    
   
}

};