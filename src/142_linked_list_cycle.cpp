
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
	ListNode *detectCycle(ListNode *head) {
		if(head==NULL) return NULL;
        ListNode* one = head;
		ListNode* two = head;
		do{
			if(!two->next || !two->next->next) return NULL;
			one = one->next;
			two = two->next->next;
		} while(one!=two);
		one = head;
		while(one!=two){
			one = one->next;
			two = two->next;
		}
		return one;
    }
};

int main(){

}
