#include<algorithm>
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
	bool hasPathSum(TreeNode* root, int sum) {
		if(root==NULL) return false;

		if(root->right==NULL && root->left==NULL) return (sum-root->val==0);
		return (hasPathSum(root->right,sum-root->val) || hasPathSum(root->left,sum-root->val));
	}
};

int main(){

}
