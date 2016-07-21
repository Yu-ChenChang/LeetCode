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
    ListNode* rotateRight(ListNode* head, int k) {
		if(k==0||head==NULL) return head;
		int size =1;
		ListNode* tail = head;
		for(;tail->next!=NULL;tail=tail->next) size++;
		if(k>=size) k%=size;
		if(!k) return head;

		ListNode* newHead = head;
		ListNode* newTail = head;
		for(int i=0;i<size-k-1;i++) newTail = newTail->next;
		newHead = newTail->next;
		newTail->next = NULL;
		tail->next = head;
		
		return newHead;
    }
};

int main(){
	ListNode *head;
	ListNode a(1);
	head = &a;
	Solution sol;
	head = sol.rotateRight(head,1);
	while(head!=NULL)
	{
		cout<<head->val<<endl;
		head = head->next;
	}
}
