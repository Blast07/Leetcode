/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    bool myCompare(vector <int> v1, vector <int> v2){
        if(v1[1]>v2[1])
            return true;
        else if(v1[1]<v2[1])
            return false;
        else
            return v1[0]<=v2[0];
    }
class Solution {
public:
    
    void vertical_util(TreeNode *root, int level,int y, map <int, vector<vector <int>>> &m){
        if (root==NULL)
            return;
        else{
             vector <int> v;
             v.push_back(root->val);
             v.push_back(y);
             m[level].push_back(v);
             vertical_util(root->left,level-1,y-1,m);
             vertical_util(root->right,level+1,y-1,m);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int, vector<vector <int>>> m;
        vector <vector <int>> res;
        vertical_util(root,0,0,m);
        for (auto i:m){
            vector <int> v;
            sort(i.second.begin(), i.second.end(), myCompare);
            for (auto e:i.second)
                v.push_back(e[0]);
            res.push_back(v);
        }
        return res;
    }
};