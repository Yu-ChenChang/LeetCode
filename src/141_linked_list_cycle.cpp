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
    bool hasCycle(ListNode *head) {
		if(head==NULL) return false;
        ListNode* one = head;
		ListNode* two = head;
		do{
			if(!two->next || !two->next->next) return false;
			two = two->next->next;
			one = one->next;
		} while(one!=two);
		return true;
    }
};

int main(){

}
