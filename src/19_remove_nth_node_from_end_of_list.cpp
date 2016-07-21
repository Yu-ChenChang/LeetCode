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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prepre = NULL, *pre = head, *pos = head;
        for(int i=0;i<n;i++)
        {
            pos = pos->next;
        }
        while(pos!=NULL)
        {
            prepre = pre;
            pre = pre->next;
            pos = pos->next;
        }
        if(prepre!=NULL) prepre->next = pre->next;
        else head = head->next;
        return head;
    }
};

int main(){

}
