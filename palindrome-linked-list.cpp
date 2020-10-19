/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool f(ListNode * &start,ListNode *mid){
        if(mid==NULL)
            return true;
        else{
            int midv = mid->val;
            if(f(start,mid->next)){
                if(midv == start->val){
                    start = start->next;
                    return true;
                }
                return false;
            }
            return false; 
        }
            
        
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true; 
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast!=NULL){
            slow = slow->next;
        }
        //reverse second half
        ListNode *prev = NULL;
        ListNode *cur = slow;
        while(cur){
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        ListNode *start = head;
        while(prev){
            if(prev->val != start->val)
                return false;
            prev = prev->next;
            start = start->next;
        }
       return true; 
    }
};