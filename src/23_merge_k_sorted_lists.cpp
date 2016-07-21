#include<iostream>
#include<vector>
#include<queue>
using namespace::std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct Order
{
    bool operator()(ListNode* a, ListNode* b) const
    {
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res=NULL, *cur=NULL;
        priority_queue<ListNode*,vector<ListNode*>,Order> pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        }
        while(!pq.empty())
        {
            if(res==NULL)
            {
                res = pq.top();
                cur = res;
            }
            else
            {
                cur->next = pq.top();
                cur = cur->next;
            }
            ListNode* tmp = pq.top()->next;
            pq.pop();
            if(tmp!=NULL) pq.push(tmp);
        }
        return res;
    }
};

int main(){
	vector<ListNode *> lists;
	ListNode a(10),b(20),c(11);
	a.next = &c;
	c.next = &b;
	ListNode * ptr = NULL;
	lists.push_back(ptr);
	Solution sol;
	ListNode * p = sol.mergeKLists(lists);
	while(p!=NULL){
		cout<<p->val<<" ";
		p = p->next;
	}	
	cout<<endl;
}
