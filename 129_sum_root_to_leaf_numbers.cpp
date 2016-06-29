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
	void search(TreeNode* root, int cur, int& res){
		if(root==NULL) return;
		cur = cur*10 + root->val;
		if(root->left==NULL && root->right==NULL)
			res += cur;
		search(root->left,cur,res);
		search(root->right,cur,res);
	}
    int sumNumbers(TreeNode* root) {
		int res = 0;
		search(root,0,res);
		return res;
    }
};

int main(){

}
