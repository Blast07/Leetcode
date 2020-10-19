class Solution {
public:
 vector <int> maxDepthAfterSplit(string &seq){
    int depth = 0;
    vector<int> res(seq.size(),0);
    for (int i=0;i<seq.size();i++){
        if (seq[i]=='(' ){
            depth++;
        }
        res[i] = depth%2;
        
        if (seq[i]==')')
            depth--;
        
    }
    return res;

}



};