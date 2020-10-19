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
void merge2list(ListNode *l1,ListNode*l2,ListNode* &res){
     if (l1==NULL && l2==NULL)
         res = NULL;
     else if(l1==NULL)
         res = l2;
     else if(l2==NULL)
         res = l1;
     else{
         ListNode* cur1=l1;
		 ListNode* cur2=l2;
		 ListNode* curRes;
		 //ListNode* 
		 while(cur1!=NULL && cur2!=NULL){
		 	if (cur1->val < cur2->val){
				if (res==NULL){
					res = cur1;
					cur1 = cur1->next;
					res->next==NULL;
					curRes = res;
				}else{
					curRes->next = cur1;
					cur1 = cur1->next;
					curRes = curRes->next;
					curRes->next = NULL;
				}
			}else{
				if (res==NULL){
					res = cur2;
					cur2 = cur2->next;
					res->next==NULL;
					curRes = res;
				}else{
					curRes->next = cur2;
					cur2 = cur2->next;
					curRes = curRes->next;
					curRes->next = NULL;
				}
				
			}

		 }
         while(cur1!=NULL){
             curRes->next = cur1;
             cur1 = cur1->next;
             curRes = curRes->next;
             curRes->next = NULL;
         }
         while(cur2!=NULL){
             curRes->next = cur2;
             cur2= cur2->next;
             curRes = curRes->next; 
             curRes->next = NULL;
             
         }
     }
 }
 ListNode* mergeKLists(vector<ListNode*>& lists) {
     ListNode *merge_head = NULL;
     ListNode *res = NULL;
     for (int i=0;i<lists.size();i++){
         merge2list(lists[i],merge_head,res);
         merge_head = res;
		 res = NULL;
     }
     return merge_head;
 }

};