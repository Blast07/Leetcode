//2

ListNode* addNumbers(ListNode* l1, ListNode* l2, int carry){
	int val1 = 0, val2 = 0;
	ListNode* next1 = NULL;
    ListNode* next2 = NULL;
    
	if (l1){
		val1 = l1->val;
		next1 = l1->next;
	}
	if (l2){
		val2 = l2->val;
		next2 = l2->next;
	}
	
	if (!l1 && !l2){
        
		if (carry)
			return new ListNode(carry);
		else
			return NULL;
	}

	ListNode * node = new ListNode();
	node->val = (val1+val2 + carry)%10;
	carry = (val1+val2+carry)/10;

	node->next = addNumbers(next1, next2, carry);

	return node;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	return addNumbers(l1, l2, 0);
}
