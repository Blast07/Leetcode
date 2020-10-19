/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
Node *cloneGraph_util(Node *node,map <int ,Node *> &visited){
	if (node==NULL){
		return NULL;
	}else{
		auto it = visited.find(node->val);
		if (it!=visited.end())
			return (*it).second;
		Node *new_node = new Node();
		new_node->val = node->val;
		visited.insert(make_pair(new_node->val,new_node));
		for (auto n:node->neighbors){
			new_node->neighbors.push_back(cloneGraph_util(n,visited));
		}
		return new_node;
	}
}
Node *cloneGraph(Node *node){
    
    map <int, Node *> visited;
    return cloneGraph_util(node,visited);
}


};