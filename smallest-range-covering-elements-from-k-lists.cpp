class Solution {
public:
//problem 632
//smallest range covering k elements

vector <int> smallestRange(vector <vector <int>> &nums){
	
	//{element, ithlist} = element & to which list it belongs
	set <pair<int,int>> kset;

	//stores the current index of kth list 
	//initialy first element of each list is used
	vector <int> kind(nums.size(),0); 

	vector <int> res(2,0);


	for (int i=0;i<nums.size();i++){
		kset.insert({nums[i][0], i});
	}

	int smallestRange = INT_MAX; 

	while(true){
		pair <int,int> smallestp = *kset.begin(); 
		pair <int,int> largestp = *kset.rbegin(); 

		if(largestp.first - smallestp.first +1 < smallestRange){
			smallestRange = largestp.first - smallestp.first+1;
			res[0] = smallestp.first;
			res[1] = largestp.first;
		}
		//smallestp is now used therefore now increment the index of its list
		kind[smallestp.second]++;
		if (smallestRange == 1 || kind[smallestp.second] == nums[smallestp.second].size())
			break;	
		//delete smallestp from set
		
		kset.erase(smallestp);
		kset.insert({nums[smallestp.second][kind[smallestp.second]], smallestp.second});
	}
	return res;

}


};