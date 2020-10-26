//1302

void dfs(TreeNode *root, int &max_ht, int cur_ht, int &res){
	if (!(root->left || root->right)){
		if (cur_ht > max_ht){
			max_ht = cur_ht;
			res = root->val;
		}else if (cur_ht == max_ht){
			res += root->val;
		}
	}else{
		if (root->left)
			dfs(root->left, max_ht, cur_ht + 1, res);

		if (root->right)
			dfs(root->right, max_ht, cur_ht + 1, res);
	}
}

int deepestLeavesSum(TreeNode* root) {
	int max_ht = 0;
	int res = 0;
	dfs(root, max_ht, cut_ht, res);

	return res;
}
