//226

TreeNode* invertTree(TreeNode* root) {
	if (root == NULL)
		return NULL;
	else{
		invertTree(root->left);
		invertTree(root->right);

		TreeNode *temp = root->right;
		root->right = root->left;
		root->left = temp;

		return root;
	}
}
