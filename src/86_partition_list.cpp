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
    ListNode* partition(ListNode* head, int x) {
		if(head==NULL) return head;
		ListNode* smHead = NULL;
		ListNode* smPtr;
		ListNode* geHead = NULL;
		ListNode* gePtr;
		ListNode* ptr = head;
		while(ptr!=NULL)
		{
			if(ptr->val<x)
			{
				if(smHead==NULL)
				{
					smHead = ptr;
					smPtr = smHead;
				}
				else
				{
					smPtr->next = ptr;
					smPtr = smPtr->next;
				}
			}
			else
			{
				if(geHead==NULL)
				{
					geHead = ptr;
					gePtr = geHead;
				}
				else
				{
					gePtr->next = ptr;
					gePtr = gePtr->next;
				}
			}
			ptr = ptr->next;
		}
		if(smHead!=NULL)
			smPtr->next = geHead;
		if(geHead!=NULL)
			gePtr->next = NULL;
		return smHead!=NULL?smHead:geHead;
    }
};

int main(){
	Solution sol;
	ListNode a(1);
	ListNode* head = &a;
	ListNode* res = sol.partition(head,0);
	while(res!=NULL)
	{
		cout<<res->val<<endl;
		res = res->next;
	}
}
