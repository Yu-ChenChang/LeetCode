#include<vector>
#include<string>
#include<iostream>
#include<stack>
using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if(root==NULL) return res;
		stack<TreeNode*> st;
		st.push(root);
		while(!st.empty()){
			TreeNode* ptr = st.top();
			st.pop();
			res.push_back(ptr->val);
			if(ptr->right) st.push(ptr->right);
			if(ptr->left) st.push(ptr->left);
		}
		return res;
    }
};

int main(){

}
