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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        while(head && head->val==val) head = head->next;
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        while(cur){
            next = cur->next;
            if(cur->val == val)
                pre->next = next;
            else
                pre = cur; 
            cur = next;
        }
        return head;
    }
};

int main(){

}
