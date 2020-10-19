class Solution {
public:
 bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.size()==0)
            return true;
        vector <bool> visited(rooms.size(),false);
        stack <int> st;
        st.push(0);
        visited[0] = true;
        
        while(!st.empty()){
            int top = st.top(); st.pop();
            for (int i=0;i<rooms[top].size();i++){
                if(!visited[rooms[top][i]]){
                    st.push(rooms[top][i]);
                    visited[rooms[top][i]] = true;
                }
                    
            }
        }
        
        for (int i=0;i<visited.size();i++){
            if(visited[i]==false)
                return false;
        }
        return true;
        
}
};