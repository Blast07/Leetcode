class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size()<s1.size())
            return false;
        int l = s1.size();
        for (int i=0;i+l-1<s2.size();i++){
            vector <int> map(26,0);
            for (int j=i,k=0;k<s1.size();j++,k++){
                map[s2[j]-'a']++;
                map[s1[k]-'a']--;
            }
            int j=0;
            for (j=0;j<26;j++){
                if(map[j]!=0)
                  break;
            }
            if(j>=26)
                return true;
        }
        return false;
        
    }
};