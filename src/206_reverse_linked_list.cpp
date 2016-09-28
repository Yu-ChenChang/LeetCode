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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* pre = NULL;
        ListNode* ptr = head;
        ListNode* next = head->next;
        while(ptr){
            next = ptr->next;
            ptr->next = pre;
            pre = ptr;
            ptr = next;
        }
        return pre;
    }
};

int main(){

}
