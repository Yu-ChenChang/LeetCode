#include<vector>
#include<string>
#include<iostream>
#include<queue>
using namespace::std;

/**
 * Definition for binary tree with next pointer.
 **/
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	TreeLinkNode* firstChild(TreeLinkNode* root){
		while(root!=NULL)
		{
			if(root->left!=NULL) return root->left;
			if(root->right!=NULL) return root->right;
			root = root->next;
		}
		return NULL;
	}
    void connect(TreeLinkNode *root) {
		queue<TreeLinkNode*> que;
		que.push(root);
		while(!que.empty()) connect_search(que);
	}
    void connect_search(queue<TreeLinkNode *>& que) {
		TreeLinkNode* root = que.front();
		que.pop();
		if(root==NULL) return;
		TreeLinkNode* left = root->left;
		TreeLinkNode* right = root->right;

		if(left!=NULL)
		{
			if(right!=NULL) left->next = right;
			else left->next = firstChild(root->next);
		}
		if(right!=NULL) right->next = firstChild(root->next);
		
		if(left!=NULL) que.push(left);
		if(right!=NULL) que.push(right);
    }
};

int main(){

}
