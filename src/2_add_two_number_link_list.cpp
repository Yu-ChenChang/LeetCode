#include<iostream>
using namespace::std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers_recursive_version(ListNode *l1, ListNode *l2) {
	if(l1->next == NULL && l2->next != NULL){
		ListNode *add = new ListNode(0);
		l1->next = add;
	}
	if(l2->next == NULL && l1->next != NULL){
		ListNode *add = new ListNode(0);
		l2->next = add;
	}
	int sum = l1->val + l2->val;
	ListNode* node = new ListNode(sum%10);
	if (l1->next == NULL){
		if(sum >=10){
			ListNode* last = new ListNode(sum/10);
			node->next = last;
		}
		return node;
	}
	else{
		if(sum >=10){
			l1->next->val += sum/10;
		}
		node->next = addTwoNumbers_recursive_version(l1->next,l2->next);
		return node;
	}
}
ListNode *addTwoNumbers_loop_version(ListNode *l1, ListNode *l2) {
	ListNode* res = NULL;
	ListNode* cur = NULL;
	int carry = 0;
	while(l1!=NULL || l2!=NULL)
	{
		if(res==NULL)
		{
			res = new ListNode(carry);
			cur = res;
		}
		else
		{
			cur->next = new ListNode(carry);
			cur = cur->next;
		}
		
		if(l1!=NULL)
		{
			cur->val += l1->val;
			l1 = l1->next;
		}
		if(l2!=NULL)
		{
			cur->val += l2->val;
			l2 = l2->next;
		}

		carry = cur->val/10;
		cur->val %=10;
	}
	return res;
}

void construct_list(ListNode* l,int integer){
	ListNode* newN = new ListNode(integer);
	l->next = newN;
}

int main(){
	ListNode* answer = new ListNode(0);
	ListNode* l1 = new ListNode(5);
	ListNode* l2 = new ListNode(6);
	construct_list(l1,1);
	answer->next = addTwoNumbers_loop_version(l1,l2);
	
	for(ListNode* it = answer->next;it!=NULL;){
		cout<<it->val<<" ";
		it = it->next;
	}
	cout<<endl;
}
