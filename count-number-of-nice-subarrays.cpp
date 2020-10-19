class Solution {
public:
int numberOfSubarrays(vector <int> &nums, int k){
	//subarray is called nice if there are k odd nums in it
	
	int i = 0;
	int j = 0;
	int countk  = 0;
	int res = 0;
	while(j<nums.size()){
		if (nums[j]%2!=0){
			//odd num
			countk++;
			if (countk == k){
				res++;
				int x = i;
				while(x<nums.size() && nums[x]%2==0){
					x++;
				}
				res += x-i;

				int y = j+1;
				while(y<nums.size() && nums[y]%2==0){
					y++;
				}
				res += y-j-1;
				res += (x-i)*(y-j-1);
				
				i = x+1;
				j = y;
				countk--;
						
			}else
				j++;
			

		}else {
			j++;
		
		}
	}
	return res;
}



};