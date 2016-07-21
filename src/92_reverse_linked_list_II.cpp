#include<vector>
#include<string>
#include<iostream>
using namespace::std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(m==n) return head;
		ListNode* left=NULL;
		ListNode* right=head;

		ListNode* pre=NULL;
		ListNode* ptr=head;

		for(int i=1;i<=n;i++)
		{
			pre = ptr;
			ptr = right;
			right = ptr->next;
			if(i<m)
			{
				if(left==NULL) left = head;
				else left = left->next;
			}
			else if(i>m)
			{
				ptr->next = pre;
			}
		}
		if(left!=NULL)
		{
			left->next->next = right;
			left->next = ptr;
		}
		else head->next = right;

		return left==NULL?ptr:head;
    }
};

int main(){
	ListNode a(3);
	ListNode b(5);
	a.next = &b;
	Solution sol;
	ListNode* res = sol.reverseBetween(&a,1,2);
	while(res!=NULL)
	{
		cout<<res->val<<" ";
		res = res->next;
	}
	cout<<endl;
}
