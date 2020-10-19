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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root)
        return {};
	vector<vector<int>> res;
	vector <TreeNode *> cur;
	vector <TreeNode *> next;

	cur.push_back(root);
	bool flag = true;
    vector <int> v;
	while(cur.size()){
		for (TreeNode *node:cur){
            v.push_back(node->val); 
			if (node->left)
				next.push_back(node->left);
			if (node->right)
				next.push_back(node->right);
		}

		if (!flag)
			reverse(v.begin(), v.end());
        
        res.push_back(v);
		cur = next;
		next = {};
        v = {}; 
		flag = !flag;
	}

	return res;
}

};