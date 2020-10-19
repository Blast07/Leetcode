/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map <int,Employee*>   emp_map;
        for (int i=0;i<employees.size();i++){
            emp_map[employees[i]->id] = employees[i];
        }
        stack <int> st;
        unordered_set <int> visited;
        visited.insert(id);
        st.push(id);
        int ans = 0; 
        while(!st.empty()){
            int top = st.top(); st.pop();
            ans += emp_map[top]->importance; 
            for (int i=0;i<emp_map[top]->subordinates.size();i++){
                if(visited.find(emp_map[top]->subordinates[i])==visited.end()){
                    st.push(emp_map[top]->subordinates[i]);
                    visited.insert(emp_map[top]->subordinates[i]);
                }
            }
        }
        return ans;
        
         
            
    }
};