class Solution {
public:
    vector <string> res;
    
    void generate(int open,int close, string str){
        if (open==0 && close==0)
            res.push_back(str);
        else if(open==0)
            generate(open,close-1,str+")");
        else if(open==close)
            generate(open-1,close,str+"(");
        else if(open<close){
            generate(open-1,close,str+"(");
            generate(open,close-1,str+")");
        }
        
    }
    vector<string> generateParenthesis(int n) {
        if (n==0) 
            return vector<string>();
        res.clear();
        generate(n,n,"");
        return res;
    }
};