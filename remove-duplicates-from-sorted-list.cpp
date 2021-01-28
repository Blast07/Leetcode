//83

ListNode* deleteDuplicates(ListNode* head) {
	ListNode *cur  = head;        
	while(cur && cur->next){
		if (cur->value == cur->next->value){
			cur->next = cur->next->next;
		}else{
			cur = cur->next;
		}
	}

	return head;
}
