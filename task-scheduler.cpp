
class Solution {
public:
    
int leastInterval(vector<char>& tasks, int n) {
	vector <int> mp(26, 0);

	for (char ch:tasks)
		mp[ch - 'A']++;

	sort(mp.begin(), mp.end());

	int chunks = mp[25]-1;
	int idleSpots = chunks*n;

	for (int i=24;i>=0;i--)
		idleSpots -= min(chunks, mp[i]);

	return idleSpots > 0 ? idleSpots + tasks.size():tasks.size();
	
}
};