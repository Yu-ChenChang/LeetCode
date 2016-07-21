#include<iostream>
#include<vector>
#include<queue>
using namespace::std;

/**
 Definition for singly-linked list.
**/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverse(ListNode *head,int k){
		if(k<=1) return head;
		ListNode *newHead = NULL;
		ListNode *cur = head;
		for(int i=0;i<k;i++)
		{
			cur = head;
			for(int j=i;j<k-2;j++)
			{
				cur = cur->next;		
			}
			if(newHead == NULL)
				newHead = cur->next;
			cur->next->next = cur; 
		}
		cur->next = NULL;
		return head = newHead;
	}
    ListNode *reverseKGroup(ListNode *head, int k) {

		ListNode *next = head;
		ListNode *cur = NULL;
		ListNode *tail = NULL;
		ListNode *pre = NULL;

		do
		{
			//update tail
			tail = next;
			for(int i=0;i<k-1;i++)
			{
				if(tail!=NULL)
					tail = tail->next;
				//this group cannot reverse -> update pre if necessary and return head;
				else
				{
					break;
				}
			}
			if(tail==NULL)
			{
				if(pre != NULL)
					pre->next = next;
				return head;
			}
			//move head to tail
			if(cur==NULL) head = tail;
			//update cur
			cur = next;
			//update next
			next = tail->next;
			//update pre
			if(pre != NULL) pre->next = tail;
			pre = cur;
			//reverse a group
			reverse(cur,k);	
		} while(cur!=NULL);

		return head;
    }
};

int main(){
	ListNode a(1),b(2),c(3),d(4),e(5),f(6),g(7);
	/*
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	*/
	ListNode * ptr = &a;
	Solution sol;
	ListNode * p = sol.reverseKGroup(ptr,2);//sol.reverseKGroup(ptr,3);
	while(p!=NULL){
		cout<<p->val<<" ";
		p = p->next;
	}	
	cout<<endl;
}
