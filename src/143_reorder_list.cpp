#include<vector>
#include<string>
#include<iostream>
using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
		if(head==NULL) return;
		ListNode* one = head;
		ListNode* two = head;
		int prelen = 0;
		while(two && two->next){
			two = two->next->next;
			one = one->next;
			prelen++;
		}
		//even length
		if(!two){
			prelen--;
		}
		//odd length
		else if(!two->next){
			two = one;
			one = one->next;
			two->next = NULL;
		}
		//one is pointed to those needed to be reversed
		ListNode* pre = NULL;
		ListNode* pos = NULL;
		while(one!=NULL){
			pos = one->next;
			one->next = pre;
			pre = one;
			one = pos;
		}
		//pre is the head one reversed list
		ListNode* left = head;
		ListNode* right = pre;

		for(int i=0;i<prelen;i++){
			pos = left->next;
			pre = right->next;

			left->next = right;
			right->next = pos;

			left = pos;
			right = pre;
		}
		return;
    }
};

int main(){
	ListNode a(1),b(2),c(3),d(4),e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	Solution sol;
	sol.reorderList(&a);
	ListNode* ptr = &a;
	while(ptr!=NULL){
		cout<<ptr->val<<" ";
		ptr = ptr->next;
	}
	cout<<endl;

}
