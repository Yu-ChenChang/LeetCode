#include<iostream>
using namespace::std;
/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		ListNode * res;       
		ListNode *front,*rear;
		if(head == NULL) return NULL;	
		else if(head->next == NULL) return head;
		res = head->next;
		while(head!=NULL&&head->next!=NULL){
			front = head->next;
			rear = head;
			head = front->next;
			front->next = rear;
		    rear->next = head==NULL?NULL:(head->next==NULL?head:head->next);
		}
		return res;
    }
};

int main(){
	ListNode a(1);
	ListNode b(2);
	a.next = &b;
	Solution sol;
	ListNode *c = sol.swapPairs(&a);
	while(c!=NULL){
		cout<<c->val<<" ";
		c = c->next;
	}
	cout<<endl;
}
