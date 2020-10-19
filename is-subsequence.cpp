class Solution {
public:
 bool isSubsequence(string s,string t){
	//return true if s is subseq of t
	//
     //two pointer solution
     
     int i=0,j=0;
     while(i<s.size() && j<t.size()){
        if (s[i] == t[j]){
            //found match
            i++;
            j++;
            
        }else
            j++;
         
     }
     if (i==s.size())
         return true;
     return false;
}

};