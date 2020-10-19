class Solution {
public:
    bool dead(unordered_set <string> &dead_set, string cur){
        if(dead_set.find(cur)==dead_set.end())
            return false;
        return true;
    }
    int openLock(vector<string>& deadends, string target) {
        
        queue <string> q;
        unordered_map <string,string> parent;
        unordered_set <string> visited;
        visited.insert("0000");
        q.push("0000");
        parent.insert(make_pair("0000", "0000"));
        unordered_set <string> dead_set;
        for (auto s:deadends)
            dead_set.insert(s);
        bool found = false;
        
        while(!q.empty()){
            string front = q.front();
            q.pop();
            if (front==target){
                found = true;
                break;
            }else{
              
                if (!dead(dead_set,front)){
                    //nodes adjacent to current
                    string temp;
                    for (int i=0;i<4;i++){
                        temp = front;
                        if (front[i]!='9'){
                            temp[i] = temp[i]+1; 
                        }else temp[i] = '0';
                        
                        if(!dead(dead_set,temp)&& visited.find(temp)==visited.end()){
                            q.push(temp);
                            visited.insert(temp);
                            parent.insert(make_pair(temp,front));
                            if (target==temp){
                                found=true;
                                break;
                            }
                        }
                        temp = front;
                        if (front[i]!='0')
                            temp[i] = temp[i]-1;
                        else temp[i] = '9';
                        
                        if(!dead(dead_set,temp)&& visited.find(temp)==visited.end()){
                            q.push(temp);
                            visited.insert(temp);
                            parent.insert(make_pair(temp,front));
                            if (target==temp){
                                found=true;
                                break;
                            }
                        }
                        
                        
                    }   
                }
                if (found)
                    break;
            }
                
        }
        
            if (!found)
                return -1;
            int steps = 0;
            string cur = target;
            while(parent[cur]!="0000"){
                steps++;
                cur = parent[cur];
            }
            steps++;
            return steps;
            
        
    }
};