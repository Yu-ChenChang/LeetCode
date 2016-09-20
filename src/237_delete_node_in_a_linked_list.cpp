#include<iostream>
#include<string>
#include<vector>
#include<map>
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
    void deleteNode(ListNode* node) {
        if(!node || !node->next) return;
		node->val = node->next->val;
		node->next = node->next->next;
    }
};

int main(){
	ListNode a(0);
	ListNode b(1);
	a.next = &b;
	Solution sol;
	sol.deleteNode(&a);
	
}
