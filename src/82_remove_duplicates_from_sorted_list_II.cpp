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
    ListNode* deleteDuplicates(ListNode* head) {
		if(head==NULL) return head;
 		ListNode* newHead = NULL;       
		ListNode* ptr = head;
		bool dFlag = false;
		while(ptr->next!=NULL)
		{
			if(ptr->val==ptr->next->val)
				dFlag = true;
			else
			{
				if(dFlag)
				{
					if(newHead==NULL)
						head = ptr->next;
					else
						newHead->next = ptr->next;
					dFlag = false;
				}
				else
				{
					if(newHead==NULL)
						newHead = head;
					else
						newHead = newHead->next;
				}
			}
			ptr = ptr->next;
		}
		if(dFlag)
		{
			if(newHead==NULL) return NULL;
			else
			{
				newHead->next = NULL;
				return head;
			}
		}
		else return head;
    }
};

int main(){
	Solution sol;
}
