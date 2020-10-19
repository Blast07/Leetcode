/*class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()==1) return 0;
        map<int,vector<int> > m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]].push_back(i);
        for(auto i: m)
            sort(i.second.begin(),i.second.end(),[](int a,int b){return a>b;});
        vector<bool> vis(arr.size(),false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int l=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int u=q.front();
                q.pop();
                if(u==arr.size()-1) return l;
                if(u-1>=0&&!vis[u-1])
                {
                    q.push(u-1);
                    vis[u-1]=true;
                }
                 if(u+1<arr.size()&&!vis[u+1])
                {
                    q.push(u+1);
                    vis[u+1]=true;
                }
                vector<int> &v=m[arr[u]];
                for(auto i:v)
                {
                    if(!vis[i])
                    {   if(i==arr.size()-1) return l+1;
                        q.push(i);
                        vis[i]=true;
                    }
                }
                v.clear();
            }
            l++;
        }
        return l;
    }
};*/
class Solution {
public:
int minJumps(vector<int>& arr) {
    if (arr.size()==1)
        return 0;
    
	unordered_map <int, vector <int>> mp;

	for (int i = 0; i<arr.size() ; i++){
		mp[arr[i]].push_back(i);	
	}
    for (auto i:mp)
        sort(i.second.begin(),i.second.end(),[](int a,int b){return a>b;});

	vector <int> visited(arr.size(), -1);

	queue <int> q;
	q.push(0);

	visited[0] = 0;

	while(q.size()){
		int front = q.front(); q.pop();	

		if (front == arr.size()-1)
			return visited[front];

		if (front + 1 < arr.size() && visited[front+1] < 0){
			q.push(front+1);
			visited[front+1] = visited[front] + 1;
		}
		
		if (front - 1 > 0 && visited[front-1] < 0){
			q.push(front-1);
			visited[front-1] = visited[front] + 1;
		}

		for (int x: mp[arr[front]]){
			if (visited[x] < 0){
				q.push(x);
				visited[x] = visited[front] + 1;
                if (x == arr.size()-1) 
                    return visited[x];
			}
			
		}
        mp[arr[front]] = {};

	}

	return 0;
}

};