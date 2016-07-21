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
		ListNode* duPtr = head;
		bool duFlag = 0;
		ListNode* ptr = head;
		while(ptr->next!=NULL)
		{
			if(ptr->val==ptr->next->val)
			{
				if(!duFlag)
				{
					duPtr = ptr;
					duFlag = true;
				}
			}
			else
			{
				if(duFlag)
				{
					duPtr->next = ptr->next;
					duFlag = false;
				}
			}
			ptr = ptr->next;
		}
		if(duFlag) duPtr->next = NULL;
		return head;
    }
};

int main(){
	Solution sol;
}
