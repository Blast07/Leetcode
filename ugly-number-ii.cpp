#define llint long long int
class Solution {
public:
    llint nthUglyNumber(llint n){
	
	llint count = 0;
	priority_queue <llint, vector <llint>, greater <llint>> min_heap;
    unordered_set <llint> visited;

	min_heap.push(1);
	while(!min_heap.empty()){
		llint min = min_heap.top(); min_heap.pop();
		count++;
		if (count==n)
			return min;

        if (visited.find(min*2)==visited.end())
		    min_heap.push(min*2), visited.insert(min*2);
        
        if (visited.find(min*3)==visited.end())
		    min_heap.push(min*3), visited.insert(min*3); 
        
        if (visited.find(min*5)==visited.end())
		    min_heap.push(min*5), visited.insert(min*5);
	}
	return 0;//dummy return 
	
}

};