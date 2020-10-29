//814

TreeNode* pruneTree(TreeNode* root) {
	if (!root)
		return NULL;
	else{
		root->left = pruneTree(root->left);
		root->right = pruneTree(root->right);
		if (root->val || root->left || root->right)
			return root;
		else
			return NULL;
	}
}
