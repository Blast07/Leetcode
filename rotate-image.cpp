class Solution {
public:
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void transpose(vector <vector <int>> &matrix){
        int n= matrix.size();
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    void mirror(vector <vector <int>> &matrix){
        int n = matrix.size();
        for(int i=0,j=n-1;i<j;i++,j--){
            for (int k=0;k<n;k++){
                swap(matrix[k][i],matrix[k][j]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        mirror(matrix);
    }
};