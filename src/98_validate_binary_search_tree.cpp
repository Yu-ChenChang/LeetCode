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

class Solution {
public:
	bool isValidBST(TreeNode* root, bool left, bool right, int leftMax, int rightMin){
		if(root->left!=NULL)
			if(root->left->val >= root->val || right&&root->left->val <= rightMin
				|| !isValidBST(root->left, true, right, root->val, rightMin)) return false;
		if(root->right!=NULL)
			if(root->right->val <= root->val || left&&root->right->val >=leftMax
				|| !isValidBST(root->right, left, true, leftMax, root->val)) return false;

		return true;
	}
    bool isValidBST(TreeNode* root) {
		if(root==NULL) return true;
		return isValidBST(root, false, false, 0, 0);
    }
};

int main(){

}
