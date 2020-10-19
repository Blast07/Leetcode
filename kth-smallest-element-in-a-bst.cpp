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
    int ksmallest(TreeNode* root, int &cur,int k){
    if(!root)
        return INT_MAX;
    else{
        int left= ksmallest(root->left,cur,k);
        if(left!=INT_MAX)
            return left;
        cur++;
        if(cur==k)
            return root->val;
        int right = ksmallest(root->right,cur,k);
        if(right!=INT_MAX)
            return right;
        return INT_MAX;
    }
    
}
    int kthSmallest(TreeNode* root, int k) {
       int cur = 0;
       return ksmallest(root,cur,k);
    }
};