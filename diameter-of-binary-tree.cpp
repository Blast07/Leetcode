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
    pair <int,int> f(TreeNode*root){
    if (root==NULL)
        return pair<int,int> (0,0);
    else{
        pair <int,int> left = f(root->left);
        pair <int,int> right = f(root->right);
        pair <int,int> res;
        res.first = max(max(left.first,right.first),left.second+right.second+1);
        res.second = max(left.second,right.second)+1;
        return res;
    }
}
int diameterOfBinaryTree(TreeNode* root) {  
    int res = f(root).first;
    return res==0?0:res-1;
}
    
};