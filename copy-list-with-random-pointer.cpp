/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL) 
            return NULL;
        Node *cur = head;
        while(cur!=NULL){
            Node *new_node = new Node(cur->val,NULL,NULL);
            new_node->next = cur->next;
            cur->next = new_node;
            cur = cur->next->next;
        }
        
        //inserting the random pointer
        cur = head;
        while(cur!=NULL){
            if (cur->random!=NULL){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next; 
        }
        Node *new_head = head->next;
        cur = head;
        while(cur!=NULL){
            Node *temp = cur->next->next;
            if (temp!=NULL)
                cur->next->next= temp->next;
            cur->next = temp;
            cur = cur->next; 
        }
        
       return new_head; 
    }
};