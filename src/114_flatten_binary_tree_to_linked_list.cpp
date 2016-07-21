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
    void flatten(TreeNode* root) {
		if(root==NULL) return;
		TreeNode* left_root = root->left;
		TreeNode* right_root = root->right;

		flatten(left_root);
		flatten(right_root);

		if(left_root!=NULL)
		{
			root->left = NULL;
			root->right = left_root;
			while(left_root->right!=NULL) 
				left_root = left_root->right;
			left_root->right = right_root;
		}
		return;
    }
};

int main(){

}
