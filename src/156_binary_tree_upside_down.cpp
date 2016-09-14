#include<vector>
#include<string>
#include<iostream>
using namespace::std;
/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	TreeNode *upsideDownBinaryTree(TreeNode *root) {
		if(!root) return NULL;
		return builder(NULL,root,NULL);	
	}
	TreeNode *builder(TreeNode *root, TreeNode *left, TreeNode *right){
		if(left==NULL){
			return root;
		}
		TreeNode* nextleft = left->left;
		TreeNode* nextright = left->right;
		left->left = right;
		left->right = root;
		root = left;
		return builder(root,nextleft,nextright);
	}
};

int main(){

}
