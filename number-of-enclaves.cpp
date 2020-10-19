class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        stack <pair <int,int>> st;
        for (int i=0;i<A[0].size();i++){
            if (A[0][i]){
                st.push(make_pair(0,i));
                A[0][i] = 0;
            }
        }
        for (int i=0;i<A[0].size();i++){
            if (A[A.size()-1][i]){
                st.push(make_pair(A.size()-1,i));
                A[A.size()-1][i] = 0;
            }
        }
        for (int i=0;i<A.size();i++){
            if (A[i][0]){
                st.push(make_pair(i,0));
                A[i][0] = 0;
            }
        }
        for (int i=0;i<A.size();i++){
            if (A[i][A[0].size()-1]){
                st.push(make_pair(i ,A[0].size()-1));
                A[i][A[0].size()-1] = 0;
            }
        }
        int n = A.size();
        int m = A[0].size();
        vector <vector <int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        while(!st.empty()){
            pair <int,int> top = st.top(); st.pop();
            for (int i=0;i<dir.size();i++){
                int x = top.first + dir[i][0];
                int y = top.second + dir[i][1];
                
                if((x>=0 && x<n) && (y>=0 && y<m)){
                    if(A[x][y]){
                        st.push(make_pair(x,y));
                        A[x][y] = 0;
                    }
                }
            }
        }
        int count = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
               if(A[i][j])
                   count++;
            }
        }
        return count;
    }
};