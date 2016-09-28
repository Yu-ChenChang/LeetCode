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
	if(!l1) return l2;
	if(!l2) return l1;
	ListNode dummy(0);
	ListNode* head = &dummy;
	int carry = 0;
	while(l1 || l2){
		int total = carry;
		if(l1){ 
			total += l1->val;
			l1 = l1->next;
		}
		if(l2){
			total += l2->val;
			l2 = l2->next;
		}
		carry = total/10;
		ListNode* ptr = new ListNode(total%10);
		head->next = ptr;
		head = head->next;
	}
	if(carry){
		ListNode* ptr = new ListNode(carry);
		head->next = ptr;
	}
	return dummy.next;
}

int main(){
}
