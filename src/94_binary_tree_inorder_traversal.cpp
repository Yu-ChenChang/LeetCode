#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<stack>
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
		if(!root) return res;
		unordered_map<TreeNode*, bool> umap;
		TreeNode* ptr = NULL;
		stack<TreeNode*> st;
		st.push(root);
		while(!st.empty()){
			ptr = st.top();
			st.pop();
			if(umap[ptr]){
				res.push_back(ptr->val);
				continue;
			}
			if(ptr->right){
				st.push(ptr->right);
			}
			if(ptr->left){
				umap[ptr] = true;
				st.push(ptr);
				st.push(ptr->left);
			}
			else{
				res.push_back(ptr->val);
			}
		}
       	return res; 
    }
};

int main(){

}
