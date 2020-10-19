class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        for (;i<name.size()&&j<typed.size();){
            if (name[i] == typed[j]){
                i++;
                j++;
            }else if(i>0 && typed[j] == name[i-1]){
                j++;
            }else
                return false;
            
        }
        if (i < name.size())
            return false;
        while(j<typed.size()){
               if(typed[j++]!=name.back())
                   return false;
        }
        return true;
    }
};