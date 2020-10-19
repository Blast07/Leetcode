class Solution {
public:
vector <int> getRow(int rowIndex){
	vector <int> prev{1}; 
    vector <int> cur;
	for (int i = 1;i<=rowIndex;i++){
        cur = {1};
	 	for (int j = 0;j<prev.size()-1;j++){
			cur.push_back(prev[j] + prev[j+1]);
		}
		cur.push_back(1);
		prev = cur;
	}
	return prev;
}

};