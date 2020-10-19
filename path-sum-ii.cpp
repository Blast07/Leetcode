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
    void pathSum(TreeNode *root,int sum,vector <vector <int>> &res,vector <int> &st){
        if (root==NULL)
            return;
        else if(root->left==NULL && root->right==NULL){
            if(root->val == sum){
                st.push_back(root->val);
                res.push_back(st);
                st.pop_back();
            }
            return;
        }else{
            st.push_back(root->val);
            if(root->left)
                pathSum(root->left,sum-root->val,res,st);
            if(root->right)
                pathSum(root->right,sum-root->val,res,st);
            st.pop_back(); 
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector <vector <int>> res;
        vector <int> st;
        pathSum(root,sum,res,st);
        return res;
    }
};