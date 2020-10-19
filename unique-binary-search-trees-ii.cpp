/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<TreeNode*> generateTrees(int n) {
        if (n==0)
            return vector<TreeNode*>();
        vector <vector <vector <TreeNode*>>> dp(n+2,vector <vector <TreeNode*>>(n+2,vector<TreeNode*>(1,NULL)));
        
        for (int i=1;i<=n;i++){
            TreeNode *new_node= new TreeNode(i);
            dp[i][i][0] = new_node;
        }
        
        for (int l=2;l<=n;l++){
            for (int j=1;j<=n-l+1;j++){
                int k = j+l-1;
                dp[j][k].clear();
                for (int r=j;r<=k;r++){
                    int left = r-1;
                    int right = r+1;
                    for (auto node_l:dp[j][left]){
                        for (auto node_r:dp[right][k]){
                            TreeNode *new_node = new TreeNode(r);
                            new_node->left = node_l;
                            new_node->right = node_r;
                            dp[j][k].push_back(new_node);
                        }
                    }
                }
            }
        }
        return dp[1][n];
    }
};