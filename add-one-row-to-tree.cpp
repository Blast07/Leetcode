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
void  addRow(TreeNode *root, int v, int d, int curD){
	if (!root) //root is null
		return;
	if (curD == d-1){
		TreeNode * new_left	 = new TreeNode(v, root->left, NULL);
		TreeNode * new_right = new TreeNode(v, NULL, root->right);

		root->left = new_left;
		root->right= new_right;
	}else{
		addRow(root->left, v, d, curD+1);
		addRow(root->right, v, d, curD+1);
		
	}
}

TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (!root)
        return NULL;
	if (d == 1){
		TreeNode *new_node = new TreeNode(v, root, NULL);
		root = new_node;
	}else
		addRow(root, v, d, 1);	

	return root;
}

};