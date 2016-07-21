/**
 * Definition for singly-linked list.
*/
#include<iostream>
using namespace::std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode * res;
		ListNode head(0);
		ListNode * cur = &head;
		res = cur;
		while(l1!=NULL&&l2!=NULL){
			if(l1->val>l2->val){
				cur->next = l2;
				l2 = l2->next;
				cur = cur->next;
			}
			else{
				cur->next = l1;
				l1 = l1->next;
				cur = cur->next;
			}
		}
		while(l1!=NULL){
			cur->next = l1;
			l1 = l1->next;
			cur = cur->next;
		}
		while(l2!=NULL){
			cur->next = l2;
			l2 = l2->next;
			cur = cur->next;
		}
		return res->next;
    }
};

int main(){
	Solution sol;
	ListNode a(2);
	ListNode b(7);
	ListNode *c = sol.mergeTwoLists(&a,&b);
	while(c!=NULL){
		cout<<c->val<<endl;
		c = c->next;	
	}
}
