//1379

void f(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &clone_target) { 
	if (!original)
		return;
	else{
		if (original == target){
			clone_target = cloned;
			return;
		}

		f(original->left, cloned->left, target, clone_target);
		f(original->right, cloned->right, target, clone_target);
			
	}
}

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
	TreeNode *clone_target= NULL;
	f(original, cloned, target, clone_target);
	return clone_target;
}
