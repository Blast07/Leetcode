//382

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int n;
    
    ListNode *root;
    Solution(ListNode* head) {
        this->root = head;
        this->n = 0;
        while(head){
            this->n++;
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int r = 1 + rand()%n;
        int cur = 1;
        ListNode *temp = root;
        while(temp){
            if (cur == r)
                return temp->val;
            temp = temp->next;
            cur++;
        }
        
        return root->val;
    }
};
