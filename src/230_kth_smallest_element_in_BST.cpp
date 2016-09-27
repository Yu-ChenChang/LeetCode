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
    int kthSmallest(TreeNode* root, int k) {
		if(!root) return 0;
		int res=0;
		int x=0;
		helper(root,x,k,res);
		return res;
    }
private:
	void helper(TreeNode* root, int& x, int k, int& res){
		if(root->left){
			helper(root->left,x,k,res);
		}
		x++;
		if(x==k){
			res = root->val;
			return;
		}
		if(root->right){
			helper(root->right,x,k,res);
		}
	}
};

int main(){

}
