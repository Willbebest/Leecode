/**********************************************************
* 题目描述： 
* 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
************************************************************/

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> ret;
	if(head==NULL)
		return ret;
	ListNode* pre=head;
	ListNode* temp=NULL;
	while(pre->next){
		temp=pre->next;
		pre->next=pre->next->next;
		temp->next=head;
		head=temp;
	}
	while(head){
		ret.push_back(head->val);
		head=head->next;
	}
	return ret;
}