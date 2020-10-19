/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
		if (!root)
			return {};
		queue <Node *> q;
		q.push(root);
		q.push(NULL);
		vector <int> cur_level;
		vector <vector <int>> res;

		while(q.size()){
			Node *front = q.front(); q.pop();
			if (!front){ //front is NULL
				res.push_back(cur_level);	
                if (q.size())
				    q.push(NULL);
				cur_level = {};			

			}else{
                
				cur_level.push_back(front->val);

				//generate children
				for (Node *child:front->children){
					q.push(child);
				}
			}
		}
		return res;
    }
};
