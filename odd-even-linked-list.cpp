/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode* oddEvenList(ListNode* head){
    if(!(head && head->next && head->next->next))
    return head;
    else{
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *starteven = even;
        while(even->next && even->next->next){
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
            
        }
        if (!(even->next)){
            odd->next = starteven;
            
        }else{
            odd->next = even->next;
            even->next = NULL;
            odd->next->next = starteven;
        }
        return head;
        
    }
}
};