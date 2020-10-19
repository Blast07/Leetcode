class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum=0;
        for (int i=0;i<s.size();i++){
            sum+= s[i]-'a';
        }
        for (int i=0;i<t.size();i++){
            sum -= t[i]-'a';
        }
        cout<<sum<<endl;
        char res = 'a'-sum;
        return res;
    }
};