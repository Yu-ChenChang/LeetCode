#include<iostream>
#include<vector>
#include<unordered_map>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if(inorder.empty() || postorder.empty() || inorder.size()!=postorder.size()) return NULL;
		unordered_map<int,int> umap;
		for(int i=0;i<inorder.size();i++)
			umap[inorder[i]] = i;
		return construct(postorder,umap,0,inorder.size()-1,0,postorder.size()-1);

    }
private:
	TreeNode* construct(vector<int>&postorder,
					unordered_map<int,int>& umap,
					int inStart,
					int inEnd,
					int postStart,
					int postEnd){
		if(inStart>inEnd || postStart>postEnd) return NULL;
		TreeNode* root = new TreeNode(postorder[postEnd]);
		int k = umap[postorder[postEnd]];

		root->left = construct(postorder,umap,inStart,k-1,postStart,postStart+k-(inStart+1));
		root->right = construct(postorder,umap,k+1,inEnd,postStart+k-inStart,postEnd-1);

		return root;
	}
};

int main(){
	Solution sol;
	int arr[] = {1,3,2};
	int arr2[] = {3,2,1};
	vector<int> inorder(arr,arr+3);
	vector<int> postorder(arr2,arr2+3);
	TreeNode * root = sol.buildTree(inorder,postorder);


}
