class Solution {
public:
    

bool checkValidString(string s) {
    vector <pair<int,int>> v;
    int count=0;
    for (char ch:s){
        if (ch=='(')
            v.push_back({'(',count});
        else if(ch==')'){
            if(v.size())
                v.pop_back();
            else{
                if(count)
                    count--;
                else
                    return false;
                    
            }
        }else
            count++;
    }
        
    while(count && v.size()){
            if(count-v.back().second){
                v.pop_back();
                count--;
            }else
                return false;
                
    }
    if (v.size())
        return false;
    return true;
}
};