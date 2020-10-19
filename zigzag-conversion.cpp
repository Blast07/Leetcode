class Solution {
public:
 string convert(string s, int numRows) {
        vector <string> v(numRows);
        int bound = 0;
        int i=0;
        bool increment = true;
        while(bound<s.size()){
            
            if (i==0 && i==numRows-1){
                v[i] += s[bound];
                bound++;
                continue;
            }
            else if (i==0)
                increment = true;
            else if(i==numRows-1)
                increment = false;
                
            v[i] +=s[bound];
            if (increment)
                i++;
                
            if (!increment)
                i--;
                
            bound++;
        }
        string ans;
        for (auto i:v){
            ans+=i;
        }
        return ans;
        
}
};