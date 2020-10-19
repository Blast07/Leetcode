class Solution {
public:
    
    bool isHappy(int n) {
    unordered_set <int> m;
    while(n!=1){
        int temp = n;
        n =0;
        while(temp!=0){
            int digit = temp%10;
            n+= digit*digit;
            temp=temp/10;
        }
        if(m.find(n)!=m.end())
            return false;
        else 
            m.insert(n);
                 
    }
    return true;
}
       
};