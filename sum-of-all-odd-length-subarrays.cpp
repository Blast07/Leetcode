class Solution {
public:

int sumOddLengthSubarrays(vector <int> &arr){
	int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int start=i+1;
        int end=n-i;
        int total=start*end;
        int odd=total/2;
        if(total%2==1)
        {
            odd++;
        }
        sum+=(arr[i]*odd);
    }

	return sum;

}

};