#include<iostream>
#include<vector>
#include<string>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.empty() || inorder.empty() || preorder.size()!=inorder.size()) return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
        unordered_map<int,int> umap;
		for(int i=0;i<inorder.size();i++)
			umap[inorder[i]] = i;

		int preIndex=1;
		construct(preorder,umap,root,true,0,umap[preorder[0]]-1,preIndex);
		construct(preorder,umap,root,false,umap[preorder[0]]+1,preorder.size()-1,preIndex);
		return root;
    }
private:
	void construct(vector<int>& preorder,
					unordered_map<int,int>& umap,
					TreeNode* parent,
					bool isLeft,
					int leftB,
					int rightB,
					int& preIndex){
		int cur = umap[preorder[preIndex]];
		if(leftB>rightB) return;

		if(isLeft)
		{
			parent->left = new TreeNode(preorder[preIndex++]);
			parent = parent->left;
		}
		else
		{
			parent->right = new TreeNode(preorder[preIndex++]);
			parent = parent->right;
		}
		if(leftB==rightB) return;
		
		construct(preorder,umap,parent,true,leftB,cur-1,preIndex);
		construct(preorder,umap,parent,false,cur+1,rightB,preIndex);
	}
};


int main(){
	Solution sol;
	int arr[] = {1,2,3};
	int arr2[] = {3,2,1};
	vector<int> preorder(arr,arr+4);
	vector<int> inorder(arr2,arr2+4);
	TreeNode * root = sol.buildTree(preorder,inorder);


}
