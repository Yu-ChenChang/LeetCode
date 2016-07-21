#include<vector>
#include<string>
#include<iostream>
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
    void connect(TreeLinkNode *root) {
		if(root==NULL) return;
		TreeLinkNode* left = root->left;
		TreeLinkNode* right = root->right;

		if(left!=NULL) left->next = right;
		if(right!=NULL && root->next!=NULL) right->next = root->next->left;

		connect(root->left);
		connect(root->right);
    }
};

int main(){

}
