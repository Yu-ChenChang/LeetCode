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
	ListNode* sortList(ListNode* head){
		if(!head) return NULL;
		if(!head->next) return head;
		ListNode* pre = NULL;
		ListNode* slow = head;
	   	ListNode* fast = head;
		while(fast && fast->next){
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL; //separate two lists
		fast = slow;
		slow = head;
		ListNode* left = sortList(slow);
		ListNode* right = sortList(fast);
		head = merge(left,right);
		return head;
	}

	ListNode* merge(ListNode* left, ListNode* right){
		if(!left) return right;
		else if(!right) return left;
		ListNode* head = new ListNode(0); //dummy
		ListNode* p = head;
		while(left && right){
			if(left->val<right->val){
				head->next = left;
				left = left->next;
			}
			else{
				head->next = right;
				right = right->next;
			}
			head = head->next;
		}
		if(left) head->next = left;
		if(right) head->next = right;
		head = p->next;
		delete p;
		return head;
	}
};

int main(){

}
