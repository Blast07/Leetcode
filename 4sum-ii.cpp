class Solution {
public:
int fourSumCount(vector <int> &A, vector <int> &B,vector <int> &C, vector<int> &D){
    unordered_map <int,int> m;
    for (int i=0; i<A.size();i++){
        for (int j=0;j<B.size();j++){
            if(m.find(A[i] + B[j])!=m.end()){
                m[A[i]+B[j]]++;
            }else 
                m[A[i]+B[j]] = 1;
        }
    }
    int res=0;
    for(int i=0;i<C.size();i++){
        for(int j=0;j<D.size();j++){
            if(m.find(-C[i]-D[j])!=m.end())
                res+=m[-C[i]-D[j]];                
        }
    }
    return res;
}
};