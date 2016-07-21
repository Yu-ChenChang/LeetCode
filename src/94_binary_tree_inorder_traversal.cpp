#include<vector>
#include<string>
#include<iostream>
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
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if(root==NULL) return res;
		unordered_map<TreeNode*,bool> leftChildStatus;
		vector<TreeNode*> nodeList;
		TreeNode* ptr = root;

		while(true)
		{
			if(leftChildStatus[ptr]==0 && ptr->left!=NULL)
			{
				nodeList.push_back(ptr);
				ptr = ptr->left;
				continue;
			}
			res.push_back(ptr->val);
			if(ptr->right!=NULL) ptr = ptr->right;
			else
			{
				if(nodeList.empty()) break;
				ptr = nodeList.back();
				nodeList.pop_back();
				leftChildStatus[ptr] = 1;
			}

		}
		return res;
    }
};

int main(){

}
