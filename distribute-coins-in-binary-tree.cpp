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
    


int distributeCoins(TreeNode* root){
    int moves =0;
    distributeCoinsUtil (root, moves);
    return moves;
}
int distributeCoinsUtil(TreeNode* root,int &moves){
    if(root==NULL)
        return 0;
    else{
        int left = distributeCoinsUtil(root->left, moves);
        int right = distributeCoinsUtil(root->right,moves);
        int d = root->val -1;
        moves += abs(left)+abs(right);
        return left + right + d;
        
    }
}
};