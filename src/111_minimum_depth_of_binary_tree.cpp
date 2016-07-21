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
	int search(TreeNode* root, int level){
		if(root->left==NULL && root->right==NULL)
			return level;
		int nextLevel=level;
		if(root->left!=NULL)
			nextLevel = search(root->left,level+1);
		if(root->right!=NULL)
			nextLevel = (nextLevel==level)?search(root->right,level+1):min(nextLevel,search(root->right,level+1));
		return nextLevel;
	}
	int minDepth(TreeNode* root) {
		if(root==NULL) return 0;
		return search(root,1);
	}
};

int main(){

}
