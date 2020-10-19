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
bool canPalindrome(vector <int> &count){
	int sum=0;
	for (int i=0;i<10;i++)
		sum += count[i];
	return (sum<=1) ? true:false;

}

int pseudoPalindromicPaths(TreeNode *root,vector <int> &count){
	if (root==NULL)
		return 0;
	else if (root->left==NULL && root->right==NULL){
		count[root->val] = !(count[root->val]);

		if(canPalindrome(count)){
			count[root->val] = !(count[root->val]);
			return 1;
		
		}
		else{
			count[root->val] = !(count[root->val]);
			return 0;
		}
	}else{
		
		count[root->val] = !(count[root->val]);

		int ans = 0;
		ans += pseudoPalindromicPaths(root->left,count);
		ans += pseudoPalindromicPaths(root->right,count);
		
		count[root->val] = !(count[root->val]);
		
		return ans;
	}
}
int pseudoPalindromicPaths(TreeNode *root){
	vector <int> count(10,0);
	return pseudoPalindromicPaths(root, count);
}



};