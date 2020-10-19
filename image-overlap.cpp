class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();        
    
        vector <vector <int>> padded_img(3*n-2, vector<int>(3*n-2, 0));
    
        for (int i = 0, pi = n-1; i<n;i++,pi++){
            for (int j=0, pj = n-1; j<n;j++,pj++){
                padded_img[pi][pj] = img2[i][j];
            }
        }
        //for (int i=0;i<padded_img.size();i++){
        //    for (int j=0;j<padded_img.size();j++){
        //        cout<<padded_img[i][j]<<" ";
        //    }cout<<endl;
        //}
        int res = 0;
        for (int x = 0; x<=padded_img.size()-n ;x++){
            for (int y=0;y<=padded_img.size()-n;y++){
                int count  = 0;
                for (int i = 0, pi=x; i<n ; i++, pi++){
                    for (int j = 0, pj=y; j<n ;j++, pj++){
                        if (img1[i][j] && (padded_img[pi][pj] == img1[i][j])){
                        count++;
                        }
                    }
                }
                res = max(res, count);
            }
        }
    
        return res;
        
    }

};