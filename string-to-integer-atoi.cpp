class Solution {
public:

int myAtoi(string str){
    int i=0;
    while(str[i]==' ')
        i++;
    int sign=1;
    if(str[i]=='+'||str[i]=='-'){
        if(str[i]=='-')
            sign=-1;
        i++;}
    else if(!(str[i]>='0' && str[i]<='9'))
        return 0;
    
    
    long int num =0;
    while(i<str.size()){
        if(!(str[i]>='0'&&str[i]<='9'))
            return num*sign;
        num = num*10+str[i]-'0';
        i++;
        if(num>INT_MAX){
            if(sign==1)
                return INT_MAX;
            else
                return INT_MIN;
        }
            
    }
    
    return int(num)*sign;
    
}



};