#include<vector>
#include<string>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(!headA || !headB) return NULL;
		ListNode* last = headA;
		while(last->next){
			last = last->next;
		}
		//connect
		last->next = headB;
		ListNode* slow = headA, *fast = headA;
		do{
			if(!fast || !fast->next){
				//disconnect
				last->next = NULL;
				return NULL;
			}
			slow = slow->next;
			fast = fast->next->next;
		}while(slow!=fast);

		slow = headA;
		while(slow!=fast){
			slow = slow->next;
			fast = fast->next;
		}
		//disconnect
		last->next = NULL;
		return slow;
        
    }
};

int main(){

}
