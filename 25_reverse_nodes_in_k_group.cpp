#include<iostream>
#include<vector>
#include<queue>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *newHead=NULL, *prepre=NULL, *pre=NULL, *cur=head;
		while(cur!=NULL&&k>1)
		{
			bool reverse=true;
			pre = cur;
			for(int i=1;i<k;i++)
			{
				cur = cur->next;
				if(cur==NULL)
				{
					reverse = false;
					break;
				}
			}
			//no need to swap
			if(!reverse)
			{
				if(newHead==NULL) newHead = pre;
				if(prepre!=NULL) prepre->next = pre;
			}
			//need to swap
			else
			{
				if(newHead==NULL) newHead = cur;
				if(prepre!=NULL) prepre->next = cur;
				//swap
				prepre = pre;
				cur = pre->next;
				for(int i=1;i<k;i++)
				{
					ListNode* next  = cur->next;
					cur->next = pre;
					pre = cur;
					cur = next;
				}
				prepre->next = cur;
			}
		}
		return newHead==NULL?head:newHead;
	}    
};

int main(){
	ListNode a(1),b(2),c(3),d(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	ListNode * ptr = &a;
	Solution sol;
	ListNode * p = sol.reverseKGroup(ptr,3);
	while(p!=NULL){
		cout<<p->val<<" ";
		p = p->next;
	}	
	cout<<endl;
}
