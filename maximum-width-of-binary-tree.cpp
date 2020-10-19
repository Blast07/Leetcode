/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
       vector <pair <unsigned long long int,TreeNode*>> v;
       vector <pair<unsigned long long int,TreeNode*>> temp;
       v.push_back(make_pair(0,root));
       unsigned long long int start=0;
       unsigned long long int end=0;
       int width=0;
       while(v.size()){
           start = v[0].first;
           end = v.back().first;
           width = max(width,int(end-start+1));
           for (int i=0;i<v.size();i++){
               if(v[i].second->left)
                   temp.push_back(make_pair(v[i].first*2+1,v[i].second->left));
               
               if(v[i].second->right)
                   temp.push_back(make_pair(v[i].first*2+2,v[i].second->right));
               
           }
           v = temp;
           temp.clear();
          
       }
       return width;
        
    }
};