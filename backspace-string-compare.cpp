class Solution {
public:
bool backspaceCompare(string S, string T) {
    int bc1=0;
    int bc2=0;
    for (int i=S.size()-1,j=T.size()-1;i>=0||j>=0;){
        
        
        if (i<0 && bc2==0 && T[j]!='#')
            return false;
        if (j<0 && bc1==0 && S[i]!='#')
            return false;
 
        if (i>=0 && S[i]=='#'){
            bc1++;
            i--;
        }
        
        if(j>=0 && T[j]=='#'){
            bc2++;
            j--;
        }
        
               
        
        if (bc1==0 && bc2==0){
          
            if(i<0 || j<0 || S[i--]!=T[j--])
                return false;
        }else{
            if (i>=0){
            if (S[i]=='#'){
                bc1++;i--;}
            else{
                if(bc1){
                    bc1--;
                i--;}
            }
            
            }
            if (j>=0){
            if (T[j]=='#'){
                bc2++;j--;}
            else{
                if(bc2){
                    bc2--;
                    j--;
                }
            }
            
            }
            
        }
        
    }
    return true;
}

};