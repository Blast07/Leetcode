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
    
    pair <int,int> withWithout(TreeNode* root){
    if (root==NULL){
        return pair <int,int>(0,0);
        
    }
    else{
        pair <int,int> l = withWithout(root->left);
        pair <int,int> r = withWithout(root->right);
        return pair<int,int>(root->val + l.second + r.second,max(l.first, l.second)+max(r.first,r.second));
    }
    
}
    
    int rob(TreeNode* root) {
        pair <int,int> res = withWithout(root);
        return max(res.first,res.second);
    }
};