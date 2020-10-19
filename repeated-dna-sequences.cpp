class Solution {
public:
    vector <string> findRepeatedDnaSequences(string s){
        unordered_map <string,int> sequences;
        vector <string> res;

        if (s.size()<10)
            return res;
        
        for (int start=0;start+9<s.size();start++)
            sequences[s.substr(start,10)]++;
        

        
        for (auto seq:sequences){
            if(seq.second>1)
                res.push_back(seq.first);
        }
        

        return res;

}

};