class Solution {
public:
    int setBitCount(int x){
        int count=0;
        while(x>0){
            x=x&(x-1);
            count++;
        }
        return count;
    }
    bool prime(int x){
        if (x==0 | x==1)
            return false;
        for (int i=2;i*i<=x;i++){
            if (x%i==0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int L, int R) {
        int count=0;
        int set_bits;
        for (int i=L;i<=R;i++){
            set_bits = setBitCount(i);
            if (prime(set_bits)){
                cout<<i<<" "<<set_bits<<endl;
                count++;
            }
        }
        return count;
    }
};