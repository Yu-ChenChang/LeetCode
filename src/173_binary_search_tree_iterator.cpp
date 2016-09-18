#include<vector>
#include<string>
#include<iostream>
#include<queue>
using namespace::std;

/**
 * Definition for binary tree
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
		helper(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return (!que.empty());
    }

    /** @return the next smallest number */
    int next() {
		int tmp = que.front();
		que.pop();
		return tmp;
    }
private:
	queue<int> que;
	void helper(TreeNode* root){
     	if(root==NULL) return;   
		if(root->left) helper(root->left);
		que.push(root->val);
		if(root->right) helper(root->right);
	}
};

int main(){
	struct TreeNode a(1);
	struct TreeNode b(2);
	a.right = &b;
	BSTIterator bst(&a);
}
