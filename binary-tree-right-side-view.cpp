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
    int rightView(TreeNode *root, int cur_level, int max_level, vector <int> &right_view){
        if (root==NULL)
            return 0;
        else{
            if(cur_level>max_level){
                right_view.push_back(root->val);
                max_level = cur_level;
            }
            int right_ht = rightView(root->right, cur_level+1,max_level,right_view);
            if (right_ht > max_level)
                max_level = right_ht;
            int left_ht = rightView(root->left, cur_level+1,max_level,right_view);
            if (left_ht > max_level)
                max_level = left_ht;
            return max_level;
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector <int> right_view;
        rightView(root,0,INT_MIN, right_view);
        return right_view;
    }
};