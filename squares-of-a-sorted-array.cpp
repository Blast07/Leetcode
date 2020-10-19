class Solution {
public:
    void merge(vector <int> &A, int neg){
        int start_neg = neg;
        int start_pos = neg+1;
        vector <int> temp;
        while(start_neg>=0 && start_pos<=A.size()-1){
            if (A[start_neg] < A[start_pos]){
                temp.push_back(A[start_neg]);
                start_neg--;
            }else{
                temp.push_back(A[start_pos]);
                start_pos++;
            }
        }
        while(start_neg>=0)
            temp.push_back(A[start_neg--]);
        
        while(start_pos<=A.size()-1)
            temp.push_back(A[start_pos++]);
        for (int i=0;i<A.size();i++)
            A[i] = temp[i];
    }
    vector<int> sortedSquares(vector<int>& A) {
        int neg = -1;
        vector <int> res;
        for (int i=0;i<A.size();i++){
            if (A[i]>0)
                break;
            A[i] = -A[i];
            neg++;
        }
        merge(A,neg);
        for (int i=0;i<A.size();i++)
            res.push_back(A[i]*A[i]);
        return res;
        
    }
};