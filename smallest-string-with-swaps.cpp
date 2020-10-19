class Solution {
public:
    std::string smallestStringWithSwaps(std::string s, std::vector <std::vector <int>> &pairs){
	string res(s.size(),'-');
	unordered_map <int, std::vector <int>> graph;

	for (int i=0;i<pairs.size();i++){
		graph[pairs[i][0]].push_back(pairs[i][1]);
		graph[pairs[i][1]].push_back(pairs[i][0]);
	}
	unordered_set <int> visited;

	for (int i=0;i<s.size();i++){
		if (visited.find(i) == visited.end()){//if not visited do dfs

			std::string chars;
			std::vector <int> indexes;


			vector <int> stack;
			stack.push_back(i);
            
			visited.insert(i);

			while(stack.size()){
				int n = stack.back(); stack.pop_back();
					
				chars += s[n];
				indexes.push_back(n);

				//get neighbors
				for (int x:graph[n]){
					if (visited.find(x)==visited.end()){
						stack.push_back(x);
                        visited.insert(x);
                    
                    }
				}
				
			}
			sort(chars.begin(), chars.end());
			sort(indexes.begin(), indexes.end());
			int i = 0;
			for (int ind:indexes){
				res[ind] = chars[i++];
			}
		}
	}
	return res;
}


};