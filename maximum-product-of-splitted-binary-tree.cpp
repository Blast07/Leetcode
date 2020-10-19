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
const int M = 1000000007;
      
class Solution {
public:
    long sumtree(TreeNode *root){
        if (!root)
            return 0;
        else
            return root->val + sumtree(root->left) + sumtree(root->right);
    }
    
    long maxproduct(TreeNode *root, long total, long &res){
        if (!root)
            return 0;
        else{
    
            long sum_ = (long)root->val + maxproduct(root->left, total, res) 
                       + maxproduct(root->right, total, res);
            
            long rem = total - sum_;
            long prod = sum_ * rem;
            
            res = max(res, prod);
    
            return sum_;
    
        }
    }
    
    int maxProduct(TreeNode *root){
        long total = sumtree(root);		
        long res = 0;
        maxproduct(root, total, res);
    
        return res%M;
    
    }

};