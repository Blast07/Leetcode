class Solution {
public:
vector <int> arrayRankTransform(vector <int> &arr){
	vector <int> temp;
	unordered_map <int,int> mp;
	for (int a:arr)
		mp[a] = 0;

	for (auto it:mp)
		temp.push_back(it.first);

	sort(temp.begin(), temp.end());

	for (int i=0;i<temp.size();i++)
		mp[temp[i]] = i+1;
	
	temp.clear();	

	for (int x:arr)
		temp.push_back(mp[x]);

	return temp;
}

};