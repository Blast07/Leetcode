//445

ListNode *helper(ListNode*l1, ListNode*l2, int &carry){
	//both l1 and l2 are same size
	ListNode *node = new ListNode();
	int sum = l1->val + l2->val;
	if (l1->next == NULL){
		node->val = sum%10;
		carry = sum/10;
	
	}else{
		node->next = helper(l1->next, l2->next, carry);
	 	sum += carry;
		node->val = sum%10;
		carry = sum/10;
	}
	return node;
}

ListNode* addNumbers(ListNode *l1, ListNode* l2, int diff){
	//digits in l1 >= digits in l2
	ListNode*res;
	int carry = 0;

	if (diff > 0){
		ListNode* node = new ListNode(0);
		diff--;
		ListNode* temp = node;

		while(diff > 0){
			temp->next = new ListNode(0);	
			temp = temp->next;
			diff--;
		}

		temp->next = l2;
		res = helper(l1, node, carry);
	}else{
		res = helper(l1, l2, carry);
	}
	
	if (carry){
		ListNode *new_node = new ListNode(carry);
		new_node->next = res;
		return new_node;
	}else
		return res;
}

int countDigits(ListNode *node){
	if (node)
		return 1 + countDigits(node->next);
	else
		return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	
	int digits1 = countDigits(l1);
	int digits2 = countDigits(l2);

	if (digits1 >= digits2){
		return addNumbers(l1, l2, digits1 - digits2);
	}
		return addNumbers(l2, l1, digits2 - digits1);
}
