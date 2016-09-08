#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

/**
 * Definition for singly-linked list with a random pointer.
 **/
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if(head==NULL) return NULL;
		RandomListNode* cur = new RandomListNode(head->label);
		unordered_map<int,RandomListNode*> visited;
		helper(cur, head, visited);
       	return cur; 
    }
	void helper(RandomListNode* head, RandomListNode* ori, unordered_map<int,RandomListNode*>& visited){
		visited[head->label]=head;
		if(ori->next!=NULL && head->next==NULL){
			if(visited[ori->next->label]==NULL) {
				RandomListNode* next = new RandomListNode(ori->next->label);
				head->next = next;
				helper(head->next,ori->next,visited);
			}
			else{
				head->next = visited[ori->next->label];
			}
		}
		if(ori->random!=NULL && head->random==NULL){
			if(visited[ori->random->label]==NULL) {
				RandomListNode* random = new RandomListNode(ori->random->label);
				head->random = random;
				helper(head->random,ori->random,visited);
			}
			else{
				head->random = visited[ori->random->label];
			}
		}
	}
};

int main(){

}
