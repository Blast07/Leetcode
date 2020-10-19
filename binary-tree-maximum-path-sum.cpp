/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    

int f(TreeNode*root,int sumup,int &maxsofar,int &maxval){
    if(root==NULL)
        return 0;
    else{
        maxval = max(maxval,root->val);
        sumup = max(sumup+root->val,0);        

        int suml = f(root->left,sumup,maxsofar,maxval);
        int sumr = f(root->right,sumup,maxsofar,maxval);
        maxsofar = max({suml+sumup,sumr+sumup,suml+sumr+root->val,maxsofar });
        return max({suml+root->val,sumr+root->val,0});
    }
}

int maxPathSum(TreeNode* root) {
    int maxval=INT_MIN;
    int maxsofar = 0;
    f(root,0,maxsofar,maxval);
    if(maxval<0)
        return maxval;
    return maxsofar;
}
};