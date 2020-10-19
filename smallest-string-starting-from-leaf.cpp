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
void smallestLeaf(TreeNode *root,string curstr, string &res){
    if(root==NULL)
        return;
	if(root->left==NULL && root->right==NULL){
		//leaf node;
        char ch = ('a' + root->val) ;
		curstr = ch + curstr;
		if (res=="" || curstr < res){
			res = curstr;
		}
	}else{
        char ch = ('a' + root->val);
		
		curstr = ch + curstr;
		smallestLeaf(root->left, curstr, res);
		smallestLeaf(root->right, curstr, res);
	}
}
string smallestFromLeaf(TreeNode *root){
	string res="";
	smallestLeaf(root,"",res);
	return res;
}

};