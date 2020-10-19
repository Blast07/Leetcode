class Solution {
public:
    int n;

    
    int helper(int curHat, vector <vector <int>> &hatToPeople, int mask,map <pair <int,int>,int> &mem){
	if (((1<<n)-1) == mask){
		return 1;
	}else if(curHat>=40){
       return 0; 
    }
    else if(mem.find({curHat, mask})!=mem.end()){
        
		return mem[{curHat, mask}];
	}else{
		int num_ways = 0;
        
    const int mod(1e9 + 7); 
        //without using this hat
        num_ways += helper(curHat+1, hatToPeople,mask,mem); 
        
        //using this hat
		for (int p:hatToPeople[curHat]){
			//if pth person is not occupied
			if (((mask>>p) & 1 )==0){
				num_ways += helper(curHat+1, hatToPeople, mask | (1<<p),mem);
                num_ways %= mod;
			}
		}

        mem[{curHat, mask}] = num_ways;
		return num_ways;
	
	}

}

int numberWays(vector <vector <int>> &hats){
	//creating hat to people making
	//hatToPeople[i] = list of people who wear/prefer ith hat
    
map <pair <int,int>,int> mem; //for memoization
	vector <vector <int>> hatToPeople(40); 
    mem.clear();
	n = hats.size();

	for (int i=0;i<hats.size();i++){
		for (int h:hats[i]){
			hatToPeople[h-1].push_back(i);
		}
	}
	
	//mask, if ith bit is set it indicates that person is occupied by some
	//hat
	int mask = 0; //10 bits for 10 people
	return helper(0,hatToPeople,mask,mem);
}

};