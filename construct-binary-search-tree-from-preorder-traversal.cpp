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
    
vector <int> pre;
vector <int> in;

int find(int &cur,int first,int last){
    int mid;
    if (cur ==pre.size())
        return -1;
    while(first<=last){
         mid=first+(last-first)/2;
        if (in[mid]==pre[cur]){
            cur++;
            return mid;
        }else if(in[mid]>pre[cur]){
            last = mid-1;
        }else
            first = mid+1;
        
    }
    
    
    return -1;
}



TreeNode* formTree(int &cur,int first,int last){
    
    int ind = find(cur,first,last);
    if (ind==-1)
        return NULL;
    else{
        TreeNode *node = new TreeNode(in[ind]);
        node->left=formTree(cur,first,ind-1);
        node->right=formTree(cur,ind+1,last);
        return node;
    }
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    
    pre = preorder;
    in = preorder;
    sort(in.begin(),in.end());
    int cur = 0;
    return formTree(cur,0,pre.size()-1);
    
}

};