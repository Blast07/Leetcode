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
    ListNode *reverseKGroup(ListNode *head,int k){
	if (head==NULL)
		return NULL;
	else {
		int count =0;
		ListNode *cur = head->next;
		ListNode *prev = head;
		ListNode *next;
		while(count<k-1 && cur!=NULL){
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
			count++;
		}//reverse back if count < nodes
		if  (count!=k-1 && cur==NULL){
		    ListNode *rcur = prev;
		    ListNode *rprev = NULL;
		    while(count>=0){
		        ListNode *rnext = rcur->next;
		        rcur->next = rprev;
		        rprev = rcur;
		        rcur = rnext;
		        count--;
		    }
		    return rprev;
		}
		head->next = reverseKGroup(cur,k);
		return prev;

	}
}
};