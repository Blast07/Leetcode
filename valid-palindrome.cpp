class Solution {
public:
    
    bool ifchar(char ch){
        return ( (ch>='A' && ch <= 'Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'));
    }
   
    char val(char ch){
       if (ch >='A' && ch<='Z')
            return 'a' + ch-'A';
       return ch;
        
    }
    bool isPalindrome(string s) {
        int l =0, r =s.size()-1;;
        while(l<r){
            if (ifchar(s[l]) && ifchar(s[r])){
                if (val(s[l]) == val(s[r])){
                    l++;
                    r--;
                }else
                    return false;
                
            }
            if (!ifchar(s[l]))
                l++;
            if(!ifchar(s[r]))
                r--;
            
        }
        return true;
    }
};