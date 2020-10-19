class Solution {
public:
    int findComplement(int num) {
        int i=30;
        for (;i>=0;i--){
            if (num&(1<<i))
                break;
        }
        for (;i>=0;i--){
            num = num^(1<<i);
        }
        return num;
        
    }
};