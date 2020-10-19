class Solution {
public:
    int paint(vector<vector<int>>& A, int i, int j) {
    if (i < 0 || j < 0 || i == A.size() || j == A.size() || A[i][j] != 1) return 0;
    A[i][j] = 2;
    return 1 + paint(A, i + 1, j) + paint(A, i - 1, j) + paint(A, i, j + 1) + paint(A, i, j - 1);
}/*
    void paint(vector <vector <int>> &A, int i,int j,int new_color,int old_color){
        if (!((i>=0 && i<A.size()) && (j>=0 && j<A[0].size())))
            return;
        else{
            if (A[i][j]==old_color){
                A[i][j] = new_color;
                paint(A, i-1, j, new_color, old_color);
                paint(A, i+1, j, new_color, old_color);
                paint(A, i, j-1, new_color, old_color);
                paint(A, i, j+1, new_color, old_color);
            }
            return;
                
        }
    }*/
    bool expand(vector <vector <int>> &A, int i,int j, int color){
        if (!((i>=0 && i<A.size()) && (j>=0 && j<A[0].size())))
            return false;
        if (A[i][j]==0)
            A[i][j] = color;
        return A[i][j]==1;
            
    }
    int shortestBridge(vector<vector<int>>& A) {
        int n=A.size();
        int i=0,j=0;
        for (int i = 0, found = 0; !found && i < A.size(); ++i)
        for (int j = 0; !found && j < A[0].size(); ++j) found = paint(A, i, j);
        //expand
        int cl = 2;
        while(1){
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    if(A[i][j]==cl &&(expand(A,i-1,j,cl+1) || expand(A,i+1,j,cl+1) || expand(A,i,j-1,cl+1) ||expand(A,i,j+1,cl+1) ))
                        return cl-2;
                }
            }
            cl++;
        }
    }
};